// Fill out your copyright notice in the Description page of Project Settings.


#include "GCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AGCharacter::AGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 将此字符设置为每帧调用 Tick()。 如果不需要，可以将其关闭以提高性能。
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");  //弹簧臂实例化
	SpringArmComp->SetupAttachment(RootComponent);                                 //将弹簧臂组件设置在根部组件

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");           //相机实例化
	CameraComp->SetupAttachment(SpringArmComp);                                    //将相机设置在弹簧臂上
}

// Called when the game starts or when spawned
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();

}

//向前或向后移动
void AGCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);  //添加移动输入，获取Actor前进向量
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

	PlayerInputComponent->BindAxis("MoveForward", this, &AGCharacter::MoveForward);  //绑定轴：前进后退

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);  //水平转向
}

