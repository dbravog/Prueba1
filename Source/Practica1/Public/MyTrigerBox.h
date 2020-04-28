// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTrigerBox.generated.h"

class UBoxComponent;

UCLASS()
class PRACTICA1_API AMyTrigerBox : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Collision;

	UPROPERTY(EditAnywhere)
	int32 totalcarsToWin;

	int32 currentCars;



public:	
	// Sets default values for this actor's properties
	AMyTrigerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
