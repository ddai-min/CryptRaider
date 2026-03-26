// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// FRotator ComponentRotation = GetComponentRotation();
	// FString ComponentRotationString = ComponentRotation.ToCompactString();
	// UE_LOG(LogTemp, Display, TEXT("Component Rotation: %s"), *ComponentRotationString);
	//
	// double TimeSeconds = GetWorld()->TimeSeconds;
	// UE_LOG(LogTemp, Display, TEXT("Time Seconds: %f"), TimeSeconds);

	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	// float Damage = 0;
	// float& DamageRef = Damage;
	// DamageRef = 5;
	// UE_LOG(LogTemp, Display, TEXT("Damage: %f"), Damage);
	// UE_LOG(LogTemp, Display, TEXT("DamageRef: %f"), DamageRef);

	// PrintDamage(Damage);
	// PrintDamageRef(Damage);

	// Out Parameter를 사용하게 되면
	// 출력용으로 사용되기 때문에 변수를 초기화 할 필요가 없다는
	// 문법적 규칙을 가지고 있다.
	float Damage;
	if (HasDamage(Damage))
	{
		PrintDamageConstRef(Damage);
	}
}

void UGrabber::PrintDamage(float Damage)
{
	Damage = 5;
	UE_LOG(LogTemp, Display, TEXT("Damage: %f"), Damage);
}

void UGrabber::PrintDamageRef(float& Damage)
{
	Damage = 10;
	UE_LOG(LogTemp, Display, TEXT("Damage: %f"), Damage);
}

void UGrabber::PrintDamageConstRef(const float& Damage)
{
	UE_LOG(LogTemp, Display, TEXT("Damage: %f"), Damage);
}

bool UGrabber::HasDamage(float& OutDamage)
{
	OutDamage = 10;
	return true;
}
