// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!GetPlayerTank()) {
		UE_LOG(LogTemp, Error, TEXT("PlayerController not found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController found: %s"), *GetPlayerTank()->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}


ATank * ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerTank);
}



ATank * ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}