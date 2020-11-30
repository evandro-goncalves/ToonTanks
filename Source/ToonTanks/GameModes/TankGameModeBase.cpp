// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	// TODO: Get references and game win/lose conditions

	// TODO: Call HandleGameStart() to initialize the start countdown, turret activation, pawn check, etc...
}

void ATankGameModeBase::ActorDied(AActor* DiedActor)
{
	// TODO: Check what type of Actor died
	// If Turret died, then tally
	// If Player died, then go to lose conotitions

	UE_LOG(LogTemp, Warning, TEXT("A Pawn Died!"));
}

void ATankGameModeBase::HandleGameStart()
{
	// TODO: Initialize the start countdown, turret activation, pawn check, etc...

	// TODO: Call Blueprint version of GameStart() 
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	// TODO: See if the player destroyed all turrets and show win results
	// TODO: Else if turret destroyed player show lose results

	// TODO: Call Blueprint version of GameOver(bool)
}
