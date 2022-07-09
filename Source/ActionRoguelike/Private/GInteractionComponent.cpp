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


// 基本交互实现
void UGInteractionComponent::PrimaryInteract()
{
	// 声明一个对象查询参数
	FCollisionObjectQueryParams ObjectQueryParams;
	// 添加对象类型到查询参数中
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	FVector EyeLocation; // 单线跟踪出发点
	FRotator EyeRotation;

	// 
	AActor* MyOwner = GetOwner();
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	// 单线跟踪终止点
	FVector End = EyeLocation + (EyeRotation.Vector() * 200);  // 200为其交互范围

	FHitResult Hit;  // 命中结果
	GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams);  // 按对象类型单线跟踪

	// 命中的Actor
	AActor* HitActor = Hit.GetActor();
	if (HitActor)
	{
		if (HitActor->Implements<UGGameplayInterface>())
		{
			APawn* MyPawn = Cast<APawn>(MyOwner);

			IGGameplayInterface::Execute_Interact(HitActor, MyPawn);
		}
	}

	// 可视化调试辅助线
	DrawDebugLine(GetWorld(), EyeLocation, End, FColor::Red, false, 2.0f, 0, 2.0f);
}