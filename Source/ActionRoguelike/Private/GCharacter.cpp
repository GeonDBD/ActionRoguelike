// Fill out your copyright notice in the Description page of Project Settings.


#include "GCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AGCharacter::AGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// �����ַ�����Ϊÿ֡���� Tick()�� �������Ҫ�����Խ���ر���������ܡ�
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");  //���ɱ�ʵ����
	SpringArmComp->SetupAttachment(RootComponent);                                 //�����ɱ���������ڸ������

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");           //���ʵ����
	CameraComp->SetupAttachment(SpringArmComp);                                    //����������ڵ��ɱ���
}

// Called when the game starts or when spawned
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();

}

//��ǰ������ƶ�
void AGCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);  //����ƶ����룬��ȡActorǰ������
}

// Called every frame
void AGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGCharacter::MoveForward);  //���᣺ǰ������

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);  //ˮƽת��
}

