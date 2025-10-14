// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlapTest.h"

// Sets default values
AOverlapTest::AOverlapTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOverlapTest::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Test"));
}

// Called every frame
void AOverlapTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

