// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TransformActor.generated.h"

UCLASS()
class TUTO3_API ATransformActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATransformActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn;

	UFUNCTION()
	void SpawnObject(FVector Loc, FRotator Rot);

	UPROPERTY(EditAnywhere)
	int32 mTime;

	UStaticMeshComponent* Mesh;

	//transform—p
	FVector Firstpos;
	FVector Secondpos;
	FTimerHandle CountdownTimerHandle;
	TArray<FVector> Varray;
	void AdvanceTimer();
	void CountdownHasFinished();
	void Event2();

};
