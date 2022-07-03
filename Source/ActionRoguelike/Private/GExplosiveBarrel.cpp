// Fill out your copyright notice in the Description page of Project Settings.


#include "GExplosiveBarrel.h"

// Sets default values
AGExplosiveBarrel::AGExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMesh>("StaticMesh");
	
}

// Called when the game starts or when spawned
void AGExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

