// Fill out your copyright notice in the Description page of Project Settings.


#include "TransformActor.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerManager.h"

// Sets default values
ATransformActor::ATransformActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	//Static Meshをアタッチ
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Mesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded()) {
		Mesh->SetStaticMesh(SphereVisualAsset.Object);
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
	}
	mTime = 10;
	
}

// Called when the game starts or when spawned
void ATransformActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ATransformActor::AdvanceTimer, 1.0f, true);
}


void ATransformActor::AdvanceTimer() {
	--mTime;
	if (mTime < 1) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void ATransformActor::CountdownHasFinished() {
	
	Mesh->SetRelativeLocation(FVector(20.0f, 20.0f, 20.0f));

	mTime = 10;
}

// Called every frame
void ATransformActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATransformActor::SpawnObject(FVector Loc, FRotator Rot)
{
	FActorSpawnParameters params;

	//AActor* SpawnedActor1 = (AActor*)GetWorld()->SpawnActor(ActorToSpawn, Loc, Rot, params);
}

