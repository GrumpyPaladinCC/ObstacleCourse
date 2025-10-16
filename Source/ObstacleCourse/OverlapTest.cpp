// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlapTest.h"
#include "Components/BoxComponent.h"

// Sets default values
AOverlapTest::AOverlapTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));

	RootComponent = trigger;

	trigger->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AOverlapTest::BeginPlay()
{
	Super::BeginPlay();



		trigger->OnComponentBeginOverlap.AddDynamic(this, &AOverlapTest::OnOverlapStart);
		UE_LOG(LogTemp, Warning, TEXT("Trigger successfully added"));
}

void AOverlapTest::OnOverlapStart(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PrintDebug(FString::Printf(TEXT("Overlap with %s"), *OtherActor->GetName()), FColor::Yellow, 5.f);
	Destroy();
}

// Called every frame
void AOverlapTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOverlapTest::PrintDebug(const FString& Message, FColor Color, float Time)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, Time, Color, Message);
	}
}

