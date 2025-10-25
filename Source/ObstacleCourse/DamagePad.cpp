// Fill out your copyright notice in the Description page of Project Settings.


#include "DamagePad.h"
#include "Components/BoxComponent.h"

// Sets default values
ADamagePad::ADamagePad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	RootComponent = trigger;
}

// Called when the game starts or when spawned
void ADamagePad::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADamagePad::overlapStart(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

// Called every frame
void ADamagePad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

