// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckpointSystem.h"
#include "Components/BoxComponent.h"
#include "ObstacleCourseCharacter.h"

// Sets default values
ACheckpointSystem::ACheckpointSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	RootComponent = trigger;

	RespawnPoint = GetActorLocation();
}

// Called when the game starts or when spawned
void ACheckpointSystem::BeginPlay()
{
	Super::BeginPlay();
	trigger->OnComponentBeginOverlap.AddDynamic(this, &ACheckpointSystem::overlapStart);
	RespawnPoint = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("2ND Trigger successfully added"));
}

void ACheckpointSystem::overlapStart(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AObstacleCourseCharacter* Player = Cast<AObstacleCourseCharacter>(OtherActor);
	if (Player)
	{
		Player->RespawnLocation = RespawnPoint;
	}
	UE_LOG(LogTemp, Warning, TEXT("Checkpoint reached, new respawn point set"));
}

// Called every frame
void ACheckpointSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

