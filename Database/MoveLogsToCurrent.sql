
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE

BEGIN TRANSACTION MoveHighStakesLogsToCurrent

	SET IDENTITY_INSERT CurrentHighStakes..Hands ON
	insert CurrentHighStakes..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogHighStakes..Hands
		where [Hand id] > all (select [Hand id] from  CurrentHighStakes..Hands)
	SET IDENTITY_INSERT CurrentHighStakes..Hands OFF
	
	SET IDENTITY_INSERT CurrentHighStakes..[Individual Results] ON
	insert CurrentHighStakes..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogHighStakes..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentHighStakes..[Individual Results])
	SET IDENTITY_INSERT CurrentHighStakes..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentHighStakes..Actions ON
	insert CurrentHighStakes..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogHighStakes..Actions
		where [Action Id] > all (select [Action Id] from  CurrentHighStakes..Actions)
	SET IDENTITY_INSERT CurrentHighStakes..Actions OFF
	
	delete  from LogHighStakes..Actions
	delete  from LogHighStakes..[Individual Results]
	delete  from LogHighStakes..Hands
	delete  from LogHighStakes..Players

COMMIT TRANSACTION MoveHighStakesLogsToCurrent

BEGIN TRANSACTION MoveCryptologicLogsToCurrent

	SET CurrentCryptologic CurrentCryptologic..Hands ON
	insert CurrentHighStakes..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogCryptologic..Hands
		where [Hand id] > all (select [Hand id] from  CurrentCryptologic..Hands)
	SET IDENTITY_INSERT CurrentCryptologic..Hands OFF
	
	SET IDENTITY_INSERT CurrentCryptologic..[Individual Results] ON
	insert CurrentCryptologic..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogCryptologic..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentCryptologic..[Individual Results])
	SET IDENTITY_INSERT CurrentCryptologic..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentCryptologic..Actions ON
	insert CurrentCryptologic..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogCryptologic..Actions
		where [Action Id] > all (select [Action Id] from  CurrentCryptologic..Actions)
	SET IDENTITY_INSERT CurrentCryptologic..Actions OFF
	
	delete  from LogCryptologic..Actions
	delete  from LogCryptologic..[Individual Results]
	delete  from LogCryptologic..Hands
	delete  from LogCryptologic..Players

COMMIT TRANSACTION MoveCryptologicLogsToCurrent

BEGIN TRANSACTION MoveLabrokesLogsToCurrent

	SET IDENTITY_INSERT CurrentLabrokes..Hands ON
	insert CurrentLabrokes..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogLabrokes..Hands
		where [Hand id] > all (select [Hand id] from  CurrentLabrokes..Hands)
	SET IDENTITY_INSERT CurrentLabrokes..Hands OFF
	
	SET IDENTITY_INSERT CurrentLabrokes..[Individual Results] ON
	insert CurrentLabrokes..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogLabrokes..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentLabrokes..[Individual Results])
	SET IDENTITY_INSERT CurrentLabrokes..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentLabrokes..Actions ON
	insert CurrentLabrokes..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogLabrokes..Actions
		where [Action Id] > all (select [Action Id] from  CurrentLabrokes..Actions)
	SET IDENTITY_INSERT CurrentLabrokes..Actions OFF
	
	delete  from LogLabrokes..Actions
	delete  from LogLabrokes..[Individual Results]
	delete  from LogLabrokes..Hands
	delete  from LogLabrokes..Players

COMMIT TRANSACTION MoveLabrokesLogsToCurrent


BEGIN TRANSACTION MoveParadiseLogsToCurrent

	SET IDENTITY_INSERT CurrentParadise..Hands ON
	insert CurrentParadise..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete, Jumbled) 
	select *  from LogParadise..Hands
		where [Hand id] > all (select [Hand id] from  CurrentParadise..Hands)
	SET IDENTITY_INSERT CurrentParadise..Hands OFF
	
	SET IDENTITY_INSERT CurrentParadise..[Individual Results] ON
	insert CurrentParadise..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogParadise..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentParadise..[Individual Results])
	SET IDENTITY_INSERT CurrentParadise..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentParadise..Actions ON
	insert CurrentParadise..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogParadise..Actions
		where [Action Id] > all (select [Action Id] from  CurrentParadise..Actions)
	SET IDENTITY_INSERT CurrentParadise..Actions OFF

	delete  from LogParadise..Actions
	delete  from LogParadise..[Individual Results]
	delete  from LogParadise..Hands
	delete  from LogParadise..Players

COMMIT TRANSACTION MoveParadiseLogsToCurrent

BEGIN TRANSACTION MovePartyLogsToCurrent

	SET IDENTITY_INSERT CurrentParty..Hands ON
	insert CurrentParty..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogParty..Hands
		where [Hand id] > all (select [Hand id] from  CurrentParty..Hands)
	SET IDENTITY_INSERT CurrentParty..Hands OFF
	
	SET IDENTITY_INSERT CurrentParty..[Individual Results] ON
	insert CurrentParty..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogParty..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentParty..[Individual Results])
	SET IDENTITY_INSERT CurrentParty..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentParty..Actions ON
	insert CurrentParty..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogParty..Actions
		where [Action Id] > all (select [Action Id] from  CurrentParty..Actions)
	SET IDENTITY_INSERT CurrentParty..Actions OFF

	delete  from LogParty..Actions
	delete  from LogParty..[Individual Results]
	delete  from LogParty..Hands
	delete  from LogParty..Players

COMMIT TRANSACTION MovePartyLogsToCurrent


BEGIN TRANSACTION MovePokerRoomLogsToCurrent

	SET IDENTITY_INSERT CurrentPokerRoom..Hands ON
	insert CurrentPokerRoom..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogPokerRoom..Hands
		where [Hand id] > all (select [Hand id] from  CurrentPokerRoom..Hands)
	SET IDENTITY_INSERT CurrentPokerRoom..Hands OFF
	
	SET IDENTITY_INSERT CurrentPokerRoom..[Individual Results] ON
	insert CurrentPokerRoom..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogPokerRoom..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentPokerRoom..[Individual Results])
	SET IDENTITY_INSERT CurrentPokerRoom..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentPokerRoom..Actions ON
	insert CurrentPokerRoom..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogPokerRoom..Actions
		where [Action Id] > all (select [Action Id] from  CurrentPokerRoom..Actions)
	SET IDENTITY_INSERT CurrentPokerRoom..Actions OFF

	delete  from LogPokerRoom..Actions
	delete  from LogPokerRoom..[Individual Results]
	delete  from LogPokerRoom..Hands
	delete  from LogPokerRoom..Players

COMMIT TRANSACTION MovePokerRoomLogsToCurrent

BEGIN TRANSACTION MoveRoyalVegasLogsToCurrent

	SET IDENTITY_INSERT CurrentRoyalVegas..Hands ON
	insert CurrentRoyalVegas..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogRoyalVegas..Hands
		where [Hand id] > all (select [Hand id] from  CurrentRoyalVegas..Hands)
	SET IDENTITY_INSERT CurrentRoyalVegas..Hands OFF
	
	SET IDENTITY_INSERT CurrentRoyalVegas..[Individual Results] ON
	insert CurrentRoyalVegas..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogRoyalVegas..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentRoyalVegas..[Individual Results])
	SET IDENTITY_INSERT CurrentRoyalVegas..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentRoyalVegas..Actions ON
	insert CurrentRoyalVegas..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogRoyalVegas..Actions
		where [Action Id] > all (select [Action Id] from  CurrentRoyalVegas..Actions)
	SET IDENTITY_INSERT CurrentRoyalVegas..Actions OFF

	delete  from LogRoyalVegas..Actions
	delete  from LogRoyalVegas..[Individual Results]
	delete  from LogRoyalVegas..Hands
	delete  from LogRoyalVegas..Players

COMMIT TRANSACTION MoveRoyalVegasLogsToCurrent


BEGIN TRANSACTION MoveThePokerClubLogsToCurrent

	SET IDENTITY_INSERT CurrentThePokerClub..Hands ON
	insert CurrentThePokerClub..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogThePokerClub..Hands
		where [Hand id] > all (select [Hand id] from  CurrentThePokerClub..Hands)
	SET IDENTITY_INSERT CurrentThePokerClub..Hands OFF
	
	SET IDENTITY_INSERT CurrentThePokerClub..[Individual Results] ON
	insert CurrentThePokerClub..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogThePokerClub..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentThePokerClub..[Individual Results])
	SET IDENTITY_INSERT CurrentThePokerClub..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentThePokerClub..Actions ON
	insert CurrentThePokerClub..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogThePokerClub..Actions
		where [Action Id] > all (select [Action Id] from  CurrentThePokerClub..Actions)
	SET IDENTITY_INSERT CurrentThePokerClub..Actions OFF

	delete  from LogThePokerClub..Actions
	delete  from LogThePokerClub..[Individual Results]
	delete  from LogThePokerClub..Hands
	delete  from LogThePokerClub..Players

COMMIT TRANSACTION MoveThePokerClubLogsToCurrent


BEGIN TRANSACTION MoveTrueLogsToCurrent

	SET IDENTITY_INSERT CurrentTrue..Hands ON
	insert CurrentTrue..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogTrue..Hands
		where [Hand id] > all (select [Hand id] from  CurrentTrue..Hands)
	SET IDENTITY_INSERT CurrentTrue..Hands OFF
	
	SET IDENTITY_INSERT CurrentTrue..[Individual Results] ON
	insert CurrentTrue..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogTrue..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentTrue..[Individual Results])
	SET IDENTITY_INSERT CurrentTrue..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentTrue..Actions ON
	insert CurrentTrue..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogTrue..Actions
		where [Action Id] > all (select [Action Id] from  CurrentTrue..Actions)
	SET IDENTITY_INSERT CurrentTrue..Actions OFF

	delete  from LogTrue..Actions
	delete  from LogTrue..[Individual Results]
	delete  from LogTrue..Hands
	delete  from LogTrue..Players

COMMIT TRANSACTION MoveTrueLogsToCurrent


BEGIN TRANSACTION MoveUltimateBetLogsToCurrent

	SET IDENTITY_INSERT CurrentUltimateBet..Hands ON
	insert CurrentUltimateBet..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogUltimateBet..Hands
		where [Hand id] > all (select [Hand id] from  CurrentUltimateBet..Hands)
	SET IDENTITY_INSERT CurrentUltimateBet..Hands OFF
	
	SET IDENTITY_INSERT CurrentUltimateBet..[Individual Results] ON
	insert CurrentUltimateBet..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogUltimateBet..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentUltimateBet..[Individual Results])
	SET IDENTITY_INSERT CurrentUltimateBet..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentUltimateBet..Actions ON
	insert CurrentUltimateBet..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogUltimateBet..Actions
		where [Action Id] > all (select [Action Id] from  CurrentUltimateBet..Actions)
	SET IDENTITY_INSERT CurrentUltimateBet..Actions OFF
	
	delete  from LogUltimateBet..Actions
	delete  from LogUltimateBet..[Individual Results]
	delete  from LogUltimateBet..Hands
	delete  from LogUltimateBet..Players

COMMIT TRANSACTION MoveUltimateBetLogsToCurrent


BEGIN TRANSACTION MoveWSEXLogsToCurrent

	SET IDENTITY_INSERT CurrentWSEX..Hands ON
	insert CurrentWSEX..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from LogWSEX..Hands
		where [Hand id] > all (select [Hand id] from  CurrentWSEX..Hands)
	SET IDENTITY_INSERT CurrentWSEX..Hands OFF
	
	SET IDENTITY_INSERT CurrentWSEX..[Individual Results] ON
	insert CurrentWSEX..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from LogWSEX..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  CurrentWSEX..[Individual Results])
	SET IDENTITY_INSERT CurrentWSEX..[Individual Results] OFF
	
	SET IDENTITY_INSERT CurrentWSEX..Actions ON
	insert CurrentWSEX..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from LogWSEX..Actions
		where [Action Id] > all (select [Action Id] from  CurrentWSEX..Actions)
	SET IDENTITY_INSERT CurrentWSEX..Actions OFF

	delete  from LogWSEX..Actions
	delete  from LogWSEX..[Individual Results]
	delete  from LogWSEX..Hands
	delete  from LogWSEX..Players

COMMIT TRANSACTION MoveWSEXLogsToCurrent


