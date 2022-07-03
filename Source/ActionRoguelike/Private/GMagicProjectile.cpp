// Fill out your copyright notice in the Description page of Project Settings.


#include "GMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/projectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AGMagicProjectile::AGMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");  //����Ĭ���Ӷ���
	SphereComp->SetCollisionProfileName("Projectile");  //Ϊ����������ײ�ļ�
	RootComponent = SphereComp;  //��������������

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;  //��ת�����ٶ�
	MovementComp->bInitialVelocityInLocalSpace = true;  //�ֲ��ռ��еĳ�ʼ�ٶ�
}

// Called when the game starts or when spawned
void AGMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

