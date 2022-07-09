// Fill out your copyright notice in the Description page of Project Settings.


#include "GItemChest.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGItemChest::AGItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 组件实例化
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	// 旋转角度系数
	TargetPitch = 110;
}

// 交互组件功能
void AGItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

// Called when the game starts or when spawned
void AGItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

