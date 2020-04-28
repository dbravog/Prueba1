// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTrigerBox.h"
#include "Components/BoxComponent.h"
#include "CarsPawn.h"

// Sets default values
AMyTrigerBox::AMyTrigerBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);

	
}

// Called when the game starts or when spawned
void AMyTrigerBox::BeginPlay()
{
	Super::BeginPlay();
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AMyTrigerBox::OnBeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AMyTrigerBox::OnEndOverlap);

}

// Called every frame
void AMyTrigerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTrigerBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	check(OtherActor);
	ACarsPawn* carPawn = CastChecked<ACarsPawn>(OtherActor);
	if (carPawn != nullptr) {
		currentCars++;
		if (currentCars >= totalcarsToWin) {
			UE_LOG(LogTemp, Warning, TEXT("Ganasste :)"));
		}
	}
}

void AMyTrigerBox::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
{
	ACarsPawn* carPawn = CastChecked<ACarsPawn>(OtherActor);
	if (carPawn != nullptr) {
		currentCars++;
	}
}