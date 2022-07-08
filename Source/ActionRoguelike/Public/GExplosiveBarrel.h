// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GExplosiveBarrel.generated.h"

class UStaticMesh;

UCLASS()
class ACTIONROGUELIKE_API AGExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGExplosiveBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMesh* StaticMesh;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
