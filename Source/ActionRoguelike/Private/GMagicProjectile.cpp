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

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");  //创建默认子对象
	SphereComp->SetCollisionProfileName("Projectile");  //为球体设置碰撞文件
	RootComponent = SphereComp;  //根组件绑定球体组件

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;  //旋转跟随速度
	MovementComp->bInitialVelocityInLocalSpace = true;  //局部空间中的初始速度
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

