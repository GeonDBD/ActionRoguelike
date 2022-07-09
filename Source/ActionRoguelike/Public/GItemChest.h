// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGameplayInterface.h"
#include "GItemChest.generated.h"

UCLASS()
class ACTIONROGUELIKE_API AGItemChest : public AActor, public IGGameplayInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AGItemChest();

	UPROPERTY(EditAnywhere)
	float TargetPitch;

	// �����������
	void Interact_Implementation(APawn* InstigatorPawn);

protected:

	// ����ĵײ��͸����������
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
