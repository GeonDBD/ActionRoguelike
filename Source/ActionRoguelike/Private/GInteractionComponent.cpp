// Fill out your copyright notice in the Description page of Project Settings.


#include "GInteractionComponent.h"
#include "GGameplayInterface.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGInteractionComponent::UGInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


// ��������ʵ��
void UGInteractionComponent::PrimaryInteract()
{
	// ����һ�������ѯ����
	FCollisionObjectQueryParams ObjectQueryParams;
	// ��Ӷ������͵���ѯ������
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	FVector EyeLocation; // ���߸��ٳ�����
	FRotator EyeRotation;

	// 
	AActor* MyOwner = GetOwner();
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	// ���߸�����ֹ��
	FVector End = EyeLocation + (EyeRotation.Vector() * 200);  // 200Ϊ�佻����Χ

	FHitResult Hit;  // ���н��
	GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams);  // ���������͵��߸���

	// ���е�Actor
	AActor* HitActor = Hit.GetActor();
	if (HitActor)
	{
		if (HitActor->Implements<UGGameplayInterface>())
		{
			APawn* MyPawn = Cast<APawn>(MyOwner);

			IGGameplayInterface::Execute_Interact(HitActor, MyPawn);
		}
	}

	// ���ӻ����Ը�����
	DrawDebugLine(GetWorld(), EyeLocation, End, FColor::Red, false, 2.0f, 0, 2.0f);
}