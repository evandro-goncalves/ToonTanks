// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

APawnTurret::APawnTurret()
{
}

void APawnTurret::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
    {
        return;
    }

    RotateTurretFunction(PlayerPawn->GetActorLocation());
}

void APawnTurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimeHandler, this, &APawnTurret::CheckFireCondition, FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::CheckFireCondition()
{
    //todo: If player is null or is dead then bail
    if (!PlayerPawn)
    {
        return;
    }
    
    // If player is in range then fire
    if (ReturnDistanceToPlayer() <= FireRange)
    {
        Fire();
    }
}

float APawnTurret::ReturnDistanceToPlayer() const
{
    if (!PlayerPawn)
    {
        return 0.f;
    }
    
    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
    Super::HandleDestruction();

    Destroy();
}
