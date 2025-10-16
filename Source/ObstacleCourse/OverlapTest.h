// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OverlapTest.generated.h"

UCLASS()
class OBSTACLECOURSE_API AOverlapTest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOverlapTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapStart(
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


protected:
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* trigger;

	void PrintDebug(const FString& Message, FColor Color = FColor::White, float Time = 2.f);
};
