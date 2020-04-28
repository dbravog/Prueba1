// Fill out your copyright notice in the Description page of Project Settings.


#include "CarsPawn.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "Components/InputComponent.h"

// Sets default values
ACarsPawn::ACarsPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SprintArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArmCòmponent"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("UCameraComp"));
	UFloatingPawnMovementComp = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("UFloatingPawnMovementComp"));

	StaticMeshComp->SetupAttachment(RootComponent);
	SprintArmComp->SetupAttachment(StaticMeshComp);
	CameraComp->SetupAttachment(SprintArmComp);

	SprintArmComp->bUsePawnControlRotation = true;
	SprintArmComp->SocketOffset = FVector(0, 0, 200);
}

// Called when the game starts or when spawned
void ACarsPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarsPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACarsPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent && "Can't found PlayerInputComponent");

	PlayerInputComponent->BindAction("PrintHola", EInputEvent::IE_Pressed, this, &ACarsPawn::OnSpaceInput);
	PlayerInputComponent->BindAxis("MoveVertical", this, &ACarsPawn::OnMoveVertical);
	PlayerInputComponent->BindAxis("MoveHorizontal", this, &ACarsPawn::OnMoveHorizontal);
	PlayerInputComponent->BindAxis("MouseHorizontal", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("MouseVertical", this, &APawn::AddControllerPitchInput);



}


void ACarsPawn::OnSpaceInput()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello, im alive"));
}

void ACarsPawn::OnMoveVertical(float axis)
{
	//UE_LOG(LogTemp, Warning, TEXT("Axis: %f"), axis);

	FVector v = GetActorForwardVector();

	AddMovementInput(v, axis);
}
void ACarsPawn::OnMoveHorizontal(float axis)
{
	//UE_LOG(LogTemp, Warning, TEXT("Axis: %f"), axis);

	FVector h = GetActorRightVector();

	AddMovementInput(GetActorRightVector(), axis);
}
