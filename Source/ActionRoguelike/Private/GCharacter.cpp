// Fill out your copyright notice in the Description page of Project Settings.


#include "GCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GInteractionComponent.h"

// Sets default values
AGCharacter::AGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 将此字符设置为每帧调用 Tick()。 如果不需要，可以将其关闭以提高性能。
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");  // 弹簧臂实例化
	SpringArmComp->SetupAttachment(RootComponent);                                 // 将弹簧臂组件设置在根部组件
	SpringArmComp->bUsePawnControlRotation = true;  // 设置Pawn控制默认为开
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");           // 相机实例化
	CameraComp->SetupAttachment(SpringArmComp);                                    // 将相机设置在弹簧臂上

	bUseControllerRotationYaw = false;  // 设置yaw控制默认为关

	GetCharacterMovement()->bOrientRotationToMovement = true;  // 将旋转定向到运动

	// 实例化交互组件
	InteractionComp = CreateAbstractDefaultSubobject<UGInteractionComponent>("InteractionComp");
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
// 调用以将功能绑定到输入
void AGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGCharacter::MoveForward);   // 绑定轴：前进后退
	PlayerInputComponent->BindAxis("MoveRight", this, &AGCharacter::MoveRight);       // 绑定轴：左右
	

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);      // 水平转向
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);  // 抬头低头

	// 普通攻击
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AGCharacter::PrimaryAttack);

	// 跳跃
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AGCharacter::StopJumping);

	// 基本交互
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &AGCharacter::PrimaryInteract);
}

// 向前或向后移动
void AGCharacter::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();  // 获取旋转控制
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), Value);  // 添加移动输入，获取Actor前进向量
}

// 左右移动
void AGCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();  // 获取旋转控制
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);  //

	AddMovementInput(RightVector, Value);   //
}

// 普通攻击
void AGCharacter::PrimaryAttack()
{
	// 实例化绑定攻击动画
	PlayAnimMontage(AttackAnim);

	// 定时器
	GetWorldTimerManager().SetTimer(TimeHandle_PrimaryAttack, this, &AGCharacter::PrimaryAttack_TimeElapsed, 0.2f);

	// 清除定时器
	//GetWorldTimerManager().ClearTimer(TimeHandle_PrimaryAttack);
}

// 普通攻击过时
void AGCharacter::PrimaryAttack_TimeElapsed()
{
	FVector HandLocation = GetMesh()->GetSocketLocation("Muzzle_01");  // 创建向量获取骨骼的"Muzzle_01"插槽

	FTransform SpawnTM = FTransform(GetControlRotation(), HandLocation);

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);
}

// 基本互动实现
void AGCharacter::PrimaryInteract()
{
	if (InteractionComp)
	{
		InteractionComp->PrimaryInteract();
	}
}
