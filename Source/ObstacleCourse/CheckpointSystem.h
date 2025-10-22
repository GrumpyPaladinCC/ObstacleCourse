// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckpointSystem.generated.h"

UCLASS()
class OBSTACLECOURSE_API ACheckpointSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckpointSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void overlapStart(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	FVector RespawnPoint;

protected:
	UPROPERTY(VisibLeAnywhere)
	class UBoxComponent* trigger;


	class uStaticMeshComponent* visualMesh;

	void PrintDebug(const FString& Message, FColor Color = FColor::White, float Time = 2.f);
};
