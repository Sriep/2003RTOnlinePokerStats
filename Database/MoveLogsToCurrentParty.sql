SET IDENTITY_INSERT CurrentParty..Players ON
insert CurrentParty..Players ([Player Id], [Nick]) select *  from LogParty..Players
SET IDENTITY_INSERT CurrentParty..Players OFF

SET IDENTITY_INSERT CurrentParty..Hands ON
insert CurrentParty..Hands ([Hand Id] , [Small bet] , [Big bet] , Ante , [Hand reference] , [Date] , Variant , Pot , 
Rake , [Flop card 1 rank] , [Flop card 1 suit] , [Flop card 2 rank] ,[Flop card 2 suit] , [Flop card 3 rank] , [Flop card 3 suit] , 
[Turn rank] , [Turn suit] , [River rank] , [River suit] ,[Active Players] , [Table name] , Incomplete) 
select *  from LogParty..Hands
SET IDENTITY_INSERT CurrentParty..Hands OFF

SET IDENTITY_INSERT CurrentParty..[Individual Results] ON
insert CurrentParty..[Individual Results] ([Individual Results Id], [FK_Hand Id], [FK_Player Id], [Position], [Win loss], 
[First Card Rank], [First Card Suit],[Second Card Rank], [Second Card Suit],Chips)
select *  from LogParty..[Individual Results]
SET IDENTITY_INSERT CurrentParty..[Individual Results] OFF

SET IDENTITY_INSERT CurrentParty..Actions ON
insert CurrentParty..Actions ([Action Id], [FK_Results Id], [Action], Amount, [Round]) 
select *  from LogParty..Actions
SET IDENTITY_INSERT CurrentParty..Actions OFF