// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());

	Super::Tick(DeltaTime);
	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();	//TODO don't fire every frame
	}
}