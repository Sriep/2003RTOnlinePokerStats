
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE

BEGIN TRANSACTION MoveCryptologicToArchive

	SET IDENTITY_INSERT ArchiveCryptologic..Players ON
	insert ArchiveCryptologic..Players ([Player Id] , [Nick]) 
		select *  from CurrentCryptologic..Players 
			where [Player id] > all (select [Player id] from  ArchiveCryptologic..Players)
	SET IDENTITY_INSERT ArchiveCryptologic..Players OFF
	
	SET IDENTITY_INSERT ArchiveCryptologic..Hands ON
	insert ArchiveCryptologic..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentCryptologic..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveCryptologic..Hands)
	SET IDENTITY_INSERT ArchiveCryptologic..Hands OFF
	
	SET IDENTITY_INSERT ArchiveCryptologic..[Individual Results] ON
	insert ArchiveCryptologic..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentCryptologic..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveCryptologic..[Individual Results])
	SET IDENTITY_INSERT ArchiveCryptologic..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveCryptologic..Actions ON
	insert ArchiveCryptologic..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentCryptologic..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveCryptologic..Actions)
	SET IDENTITY_INSERT ArchiveCryptologic..Actions OFF
	
	delete  from CurrentCryptologic..Actions
	delete  from CurrentCryptologic..[Individual Results]
	delete  from CurrentCryptologic..Hands	

COMMIT TRANSACTION MoveCryptologicToArchive


BEGIN TRANSACTION MoveHighStakesCurrentToArchive

	SET IDENTITY_INSERT ArchiveHighStakes..Players ON
	insert ArchiveHighStakes..Players ([Player Id] , [Nick]) 
		select *  from CurrentHighStakes..Players 
			where [Player id] > all (select [Player id] from  ArchiveHighStakes..Players)
	SET IDENTITY_INSERT ArchiveHighStakes..Players OFF
	
	SET IDENTITY_INSERT ArchiveHighStakes..Hands ON
	insert ArchiveHighStakes..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentHighStakes..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveHighStakes..Hands)
	SET IDENTITY_INSERT ArchiveHighStakes..Hands OFF
	
	SET IDENTITY_INSERT ArchiveHighStakes..[Individual Results] ON
	insert ArchiveHighStakes..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentHighStakes..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveHighStakes..[Individual Results])
	SET IDENTITY_INSERT ArchiveHighStakes..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveHighStakes..Actions ON
	insert ArchiveHighStakes..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentHighStakes..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveHighStakes..Actions)
	SET IDENTITY_INSERT ArchiveHighStakes..Actions OFF
	
	delete  from CurrentHighStakes..Actions
	delete  from CurrentHighStakes..[Individual Results]
	delete  from CurrentHighStakes..Hands	

COMMIT TRANSACTION MoveHighStakesCurrentToArchive

BEGIN TRANSACTION MoveLabrokesCurrentToArchive
	
	SET IDENTITY_INSERT ArchiveLabrokes..Players ON
	insert ArchiveLabrokes..Players ([Player Id] , [Nick]) 
		select *  from CurrentLabrokes..Players 
			where [Player id] > all (select [Player id] from  ArchiveLabrokes..Players)
	SET IDENTITY_INSERT ArchiveLabrokes..Players OFF
	
	SET IDENTITY_INSERT ArchiveLabrokes..Hands ON
	insert ArchiveLabrokes..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentLabrokes..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveLabrokes..Hands)
	SET IDENTITY_INSERT ArchiveLabrokes..Hands OFF
	
	SET IDENTITY_INSERT ArchiveLabrokes..[Individual Results] ON
	insert ArchiveLabrokes..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentLabrokes..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveLabrokes..[Individual Results])
	SET IDENTITY_INSERT ArchiveLabrokes..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveLabrokes..Actions ON
	insert ArchiveLabrokes..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentLabrokes..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveLabrokes..Actions)
	SET IDENTITY_INSERT ArchiveLabrokes..Actions OFF
	
	delete  from CurrentLabrokes..Actions
	delete  from CurrentLabrokes..[Individual Results]
	delete  from CurrentLabrokes..Hands

COMMIT TRANSACTION MoveLabrokesCurrentToArchive

BEGIN TRANSACTION MoveParadiseCurrentToArchive
	
	SET IDENTITY_INSERT ArchiveParadise..Players ON
	insert ArchiveParadise..Players ([Player Id] , [Nick]) 
		select *  from CurrentParadise..Players 
			where [Player id] > all (select [Player id] from  ArchiveParadise..Players)
	SET IDENTITY_INSERT ArchiveParadise..Players OFF
	
	delete from CurrentParadise..Hands where Jumbled = 1

	SET IDENTITY_INSERT ArchiveParadise..Hands ON
	insert ArchiveParadise..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete, Jumbled) 
	select *  from CurrentParadise..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveParadise..Hands)
	SET IDENTITY_INSERT ArchiveParadise..Hands OFF
	
	SET IDENTITY_INSERT ArchiveParadise..[Individual Results] ON
	insert ArchiveParadise..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentParadise..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveParadise..[Individual Results])
	SET IDENTITY_INSERT ArchiveParadise..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveParadise..Actions ON
	insert ArchiveParadise..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentParadise..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveParadise..Actions)
	SET IDENTITY_INSERT ArchiveParadise..Actions OFF
	
	delete  from CurrentParadise..Actions
	delete  from CurrentParadise..[Individual Results]
	delete  from CurrentParadise..Hands

COMMIT TRANSACTION MoveParadiseCurrentToArchive	

BEGIN TRANSACTION MovePartyCurrentToArchive
	
	SET IDENTITY_INSERT ArchiveParty..Players ON
	insert ArchiveParty..Players ([Player Id] , [Nick]) 
		select *  from CurrentParty..Players 
			where [Player id] > all (select [Player id] from  ArchiveParty..Players)
	SET IDENTITY_INSERT ArchiveParty..Players OFF
	
	SET IDENTITY_INSERT ArchiveParty..Hands ON
	insert ArchiveParty..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentParty..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveParty..Hands)
	SET IDENTITY_INSERT ArchiveParty..Hands OFF
	
	SET IDENTITY_INSERT ArchiveParty..[Individual Results] ON
	insert ArchiveParty..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentParty..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveParty..[Individual Results])
	SET IDENTITY_INSERT ArchiveParty..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveParty..Actions ON
	insert ArchiveParty..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentParty..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveParty..Actions)
	SET IDENTITY_INSERT ArchiveParty..Actions OFF
	

	delete  from CurrentParty..Actions
	delete  from CurrentParty..[Individual Results]
	delete  from CurrentParty..Hands

COMMIT TRANSACTION MovePartyCurrentToArchive


BEGIN TRANSACTION MovePokerRoomCurrentToArchive	
	
	SET IDENTITY_INSERT ArchivePokerRoom..Players ON
	insert ArchivePokerRoom..Players ([Player Id] , [Nick]) 
		select *  from CurrentPokerRoom..Players 
			where [Player id] > all (select [Player id] from  ArchivePokerRoom..Players)
	SET IDENTITY_INSERT ArchivePokerRoom..Players OFF
	
	SET IDENTITY_INSERT ArchivePokerRoom..Hands ON
	insert ArchivePokerRoom..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentPokerRoom..Hands
		where [Hand id] > all (select [Hand id] from  ArchivePokerRoom..Hands)
	SET IDENTITY_INSERT ArchivePokerRoom..Hands OFF
	
	SET IDENTITY_INSERT ArchivePokerRoom..[Individual Results] ON
	insert ArchivePokerRoom..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentPokerRoom..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchivePokerRoom..[Individual Results])
	SET IDENTITY_INSERT ArchivePokerRoom..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchivePokerRoom..Actions ON
	insert ArchivePokerRoom..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentPokerRoom..Actions
		where [Action Id] > all (select [Action Id] from  ArchivePokerRoom..Actions)
	SET IDENTITY_INSERT ArchivePokerRoom..Actions OFF
	
	delete  from CurrentPokerRoom..Actions
	delete  from CurrentPokerRoom..[Individual Results]
	delete  from CurrentPokerRoom..Hands

COMMIT TRANSACTION MovePokerRoomCurrentToArchive

BEGIN TRANSACTION MoveRoyalVegasCurrentToArchive

	
	SET IDENTITY_INSERT ArchiveRoyalVegas..Players ON
	insert ArchiveRoyalVegas..Players ([Player Id] , [Nick]) 
		select *  from CurrentRoyalVegas..Players 
			where [Player id] > all (select [Player id] from  ArchiveRoyalVegas..Players)
	SET IDENTITY_INSERT ArchiveRoyalVegas..Players OFF
	
	SET IDENTITY_INSERT ArchiveRoyalVegas..Hands ON
	insert ArchiveRoyalVegas..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentRoyalVegas..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveRoyalVegas..Hands)
	SET IDENTITY_INSERT ArchiveRoyalVegas..Hands OFF
	
	SET IDENTITY_INSERT ArchiveRoyalVegas..[Individual Results] ON
	insert ArchiveRoyalVegas..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentRoyalVegas..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveRoyalVegas..[Individual Results])
	SET IDENTITY_INSERT ArchiveRoyalVegas..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveRoyalVegas..Actions ON
	insert ArchiveRoyalVegas..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentRoyalVegas..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveRoyalVegas..Actions)
	SET IDENTITY_INSERT ArchiveRoyalVegas..Actions OFF
	
	delete  from CurrentRoyalVegas..Actions
	delete  from CurrentRoyalVegas..[Individual Results]
	delete  from CurrentRoyalVegas..Hands

COMMIT TRANSACTION MoveRoyalVegasCurrentToArchive


BEGIN TRANSACTION MoveThePokerClubCurrentToArchive
	
	SET IDENTITY_INSERT ArchiveThePokerClub..Players ON
	insert ArchiveThePokerClub..Players ([Player Id] , [Nick]) 
		select *  from CurrentThePokerClub..Players 
			where [Player id] > all (select [Player id] from  ArchiveThePokerClub..Players)
	SET IDENTITY_INSERT ArchiveThePokerClub..Players OFF
	
	SET IDENTITY_INSERT ArchiveThePokerClub..Hands ON
	insert ArchiveThePokerClub..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentThePokerClub..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveThePokerClub..Hands)
	SET IDENTITY_INSERT ArchiveThePokerClub..Hands OFF
	
	SET IDENTITY_INSERT ArchiveThePokerClub..[Individual Results] ON
	insert ArchiveThePokerClub..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentThePokerClub..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveThePokerClub..[Individual Results])
	SET IDENTITY_INSERT ArchiveThePokerClub..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveThePokerClub..Actions ON
	insert ArchiveThePokerClub..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentThePokerClub..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveThePokerClub..Actions)
	SET IDENTITY_INSERT ArchiveThePokerClub..Actions OFF
	
	delete  from CurrentThePokerClub..Actions
	delete  from CurrentThePokerClub..[Individual Results]
	delete  from CurrentThePokerClub..Hands

COMMIT TRANSACTION MoveThePokerClubCurrentToArchive


BEGIN TRANSACTION MoveTrueCurrentToArchive
	
	SET IDENTITY_INSERT ArchiveTrue..Players ON
	insert ArchiveTrue..Players ([Player Id] , [Nick]) 
		select *  from CurrentTrue..Players 
			where [Player id] > all (select [Player id] from  ArchiveTrue..Players)
	SET IDENTITY_INSERT ArchiveTrue..Players OFF
	
	SET IDENTITY_INSERT ArchiveTrue..Hands ON
	insert ArchiveTrue..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentTrue..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveTrue..Hands)
	SET IDENTITY_INSERT ArchiveTrue..Hands OFF
	
	SET IDENTITY_INSERT ArchiveTrue..[Individual Results] ON
	insert ArchiveTrue..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentTrue..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveTrue..[Individual Results])
	SET IDENTITY_INSERT ArchiveTrue..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveTrue..Actions ON
	insert ArchiveTrue..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentTrue..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveTrue..Actions)
	SET IDENTITY_INSERT ArchiveTrue..Actions OFF
	
	delete  from CurrentTrue..Actions
	delete  from CurrentTrue..[Individual Results]
	delete  from CurrentTrue..Hands

COMMIT TRANSACTION MoveTrueCurrentToArchive


BEGIN TRANSACTION MoveUltimateBetCurrentToArchive
	
	SET IDENTITY_INSERT ArchiveUltimateBet..Players ON
	insert ArchiveUltimateBet..Players ([Player Id] , [Nick]) 
		select *  from CurrentUltimateBet..Players 
			where [Player id] > all (select [Player id] from  ArchiveUltimateBet..Players)
	SET IDENTITY_INSERT ArchiveUltimateBet..Players OFF
	
	SET IDENTITY_INSERT ArchiveUltimateBet..Hands ON
	insert ArchiveUltimateBet..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentUltimateBet..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveUltimateBet..Hands)
	SET IDENTITY_INSERT ArchiveUltimateBet..Hands OFF
	
	SET IDENTITY_INSERT ArchiveUltimateBet..[Individual Results] ON
	insert ArchiveUltimateBet..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentUltimateBet..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveUltimateBet..[Individual Results])
	SET IDENTITY_INSERT ArchiveUltimateBet..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveUltimateBet..Actions ON
	insert ArchiveUltimateBet..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentUltimateBet..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveUltimateBet..Actions)
	SET IDENTITY_INSERT ArchiveUltimateBet..Actions OFF
	
	delete  from CurrentUltimateBet..Actions
	delete  from CurrentUltimateBet..[Individual Results]
	delete  from CurrentUltimateBet..Hands

COMMIT TRANSACTION MoveUltimateBetCurrentToArchive


BEGIN TRANSACTION MoveWSEXCurrentToArchive
	
	SET IDENTITY_INSERT ArchiveWSEX..Players ON
	insert ArchiveWSEX..Players ([Player Id] , [Nick]) 
		select *  from CurrentWSEX..Players 
			where [Player id] > all (select [Player id] from  ArchiveWSEX..Players)
	SET IDENTITY_INSERT ArchiveWSEX..Players OFF
	
	SET IDENTITY_INSERT ArchiveWSEX..Hands ON
	insert ArchiveWSEX..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
	Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
	[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
	select *  from CurrentWSEX..Hands
		where [Hand id] > all (select [Hand id] from  ArchiveWSEX..Hands)
	SET IDENTITY_INSERT ArchiveWSEX..Hands OFF
	
	SET IDENTITY_INSERT ArchiveWSEX..[Individual Results] ON
	insert ArchiveWSEX..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
	[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
	select *  from CurrentWSEX..[Individual Results]
		where [Individual Results Id] > all (select [Individual Results Id] from  ArchiveWSEX..[Individual Results])
	SET IDENTITY_INSERT ArchiveWSEX..[Individual Results] OFF
	
	SET IDENTITY_INSERT ArchiveWSEX..Actions ON
	insert ArchiveWSEX..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
	select *  from CurrentWSEX..Actions
		where [Action Id] > all (select [Action Id] from  ArchiveWSEX..Actions)
	SET IDENTITY_INSERT ArchiveWSEX..Actions OFF

	delete  from CurrentWSEX..Actions
	delete  from CurrentWSEX..[Individual Results]
	delete  from CurrentWSEX..Hands

COMMIT TRANSACTION MoveWSEXCurrentToArchive

