// Fill out your copyright notice in the Description page of Project Settings.


#include "GItemChest.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGItemChest::AGItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ���ʵ����
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	// ��ת�Ƕ�ϵ��
	TargetPitch = 110;
}

// �����������
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

