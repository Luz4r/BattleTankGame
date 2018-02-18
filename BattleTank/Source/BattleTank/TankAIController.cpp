// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	/*if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possesing: %s"), *ControlledTank->GetName());
	}*/

	if (!GetPlayerTank()) {
		UE_LOG(LogTemp, Error, TEXT("PlayerController not found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController found: %s"), *GetPlayerTank()->GetName());
	}
}

ATank * ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	return (ATank*)PlayerTank;
}



ATank * ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}