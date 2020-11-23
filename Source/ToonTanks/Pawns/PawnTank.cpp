// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APawnTank::APawnTank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

void APawnTank::BeginPlay()
{
    Super::BeginPlay();

    PlayerControllerRef = Cast<APlayerController>(GetController());
}

void APawnTank::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    
    Move();
    Rotate();

    if (PlayerControllerRef)
    {
        FHitResult TraceHitResult;
        
        PlayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);

        FVector HitLocation = TraceHitResult.ImpactPoint;

        RotateTurretFunction(HitLocation);
    }
}

void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
    PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);
}

void APawnTank::CalculateMoveInput(float Value)
{
    MoveDirection = FVector(Value * MoveSpeed * GetWorld()->GetDeltaSeconds(), 0.f, 0.f);
}

void APawnTank::CalculateRotateInput(float Value)
{
    const FRotator Rotation = FRotator(0.f, Value * RotateSpeed * GetWorld()->GetDeltaSeconds(), 0.f);

    RotationDirection = FQuat(Rotation);
}

void APawnTank::Move()
{
    AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate()
{
    AddActorLocalRotation(RotationDirection, true);
}

void APawnTank::HandleDestruction()
{
    Super::HandleDestruction();

    //TODO: Hide actor
}
