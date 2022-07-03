// Fill out your copyright notice in the Description page of Project Settings.


#include "GCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AGCharacter::AGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// �����ַ�����Ϊÿ֡���� Tick()�� �������Ҫ�����Խ���ر���������ܡ�
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");  //���ɱ�ʵ����
	SpringArmComp->SetupAttachment(RootComponent);                                 //�����ɱ���������ڸ������
	SpringArmComp->bUsePawnControlRotation = true;  //����Pawn����Ĭ��Ϊ��

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");           //���ʵ����
	CameraComp->SetupAttachment(SpringArmComp);                                    //����������ڵ��ɱ���

	bUseControllerRotationYaw = false;  //����yaw����Ĭ��Ϊ��

	GetCharacterMovement()->bOrientRotationToMovement = true;  //����ת�����˶�
}

// Called when the game starts or when spawned
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();

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
	PlayerInputComponent->BindAxis("MoveRight", this, &AGCharacter::MoveRight);  //���᣺����

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);  //ˮƽת��
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);  //̧ͷ��ͷ

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AGCharacter::PrimaryAttack);
}

//��ǰ������ƶ�
void AGCharacter::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();  //��ȡ��ת����
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), Value);  //����ƶ����룬��ȡActorǰ������
}

//�����ƶ�
void AGCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();  //��ȡ��ת����
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);  //

	AddMovementInput(RightVector, Value);   //
}

//��ͨ����
void AGCharacter::PrimaryAttack()
{
	FVector HandLocation = GetMesh()->GetSocketLocation("Muzzle_01");  //����������ȡ������"Muzzle_01"���

	FTransform SpawnTM = FTransform(GetControlRotation(), HandLocation);

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);
}
