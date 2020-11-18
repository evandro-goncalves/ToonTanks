// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

public:
	// Constructors and overrides
	APawnTank();
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UCameraComponent* Camera;

	FVector MoveDirection;		// Used to calculate movement direction
	FQuat RotationDirection;	// Used to calculate rotation direction
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Rate", meta = (AllowPrivateAccess = "true")) float MoveSpeed = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Rate", meta = (AllowPrivateAccess = "true")) float RotateSpeed = 100.f;

	// Update MoveDirection based on input
	void CalculateMoveInput(float Value);

	// Update RotationDirection based on input
	void CalculateRotateInput(float Value);

	// Check every frame for movement and rotation changes and apply it to the pawn
	void Move();
	void Rotate();
};
