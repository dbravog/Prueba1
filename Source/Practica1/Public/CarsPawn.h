// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CarsPawn.generated.h"

class UstaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;

UCLASS()
class PRACTICA1_API ACarsPawn : public APawn
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		UFloatingPawnMovement* UFloatingPawnMovementComp;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SprintArmComp;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* CameraComp;


public:
	// Sets default values for this pawn's properties
	ACarsPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void OnSpaceInput();
	void OnMoveVertical(float axis);
	void OnMoveHorizontal(float axis);
};
