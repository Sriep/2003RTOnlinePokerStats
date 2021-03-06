/****** Object:  Database PokerData    Script Date: 11/02/2003 2:40:48 PM ******/
IF EXISTS (SELECT name FROM master.dbo.sysdatabases WHERE name = N'PokerData')
	DROP DATABASE [PokerData]
GO

CREATE DATABASE [PokerData]  ON (NAME = N'PokerData_Data', FILENAME = N'C:\Program Files\Microsoft SQL Server\80\Tools\data\PokerData_Data.MDF' , SIZE = 2, FILEGROWTH = 10%) LOG ON (NAME = N'PokerData_Log', FILENAME = N'C:\Program Files\Microsoft SQL Server\80\Tools\data\PokerData_Log.LDF' , SIZE = 7, FILEGROWTH = 10%)
GO

exec sp_dboption N'PokerData', N'autoclose', N'true'
GO

exec sp_dboption N'PokerData', N'bulkcopy', N'false'
GO

exec sp_dboption N'PokerData', N'trunc. log', N'true'
GO

exec sp_dboption N'PokerData', N'torn page detection', N'true'
GO

exec sp_dboption N'PokerData', N'read only', N'false'
GO

exec sp_dboption N'PokerData', N'dbo use', N'false'
GO

exec sp_dboption N'PokerData', N'single', N'false'
GO

exec sp_dboption N'PokerData', N'autoshrink', N'true'
GO

exec sp_dboption N'PokerData', N'ANSI null default', N'false'
GO

exec sp_dboption N'PokerData', N'recursive triggers', N'false'
GO

exec sp_dboption N'PokerData', N'ANSI nulls', N'false'
GO

exec sp_dboption N'PokerData', N'concat null yields null', N'false'
GO

exec sp_dboption N'PokerData', N'cursor close on commit', N'false'
GO

exec sp_dboption N'PokerData', N'default to local cursor', N'false'
GO

exec sp_dboption N'PokerData', N'quoted identifier', N'false'
GO

exec sp_dboption N'PokerData', N'ANSI warnings', N'false'
GO

exec sp_dboption N'PokerData', N'auto create statistics', N'true'
GO

exec sp_dboption N'PokerData', N'auto update statistics', N'true'
GO

use [PokerData]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_Hands_Game Hosts]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[Hands] DROP CONSTRAINT FK_Hands_Game Hosts
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_Players_Game Hosts]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[Players] DROP CONSTRAINT FK_Players_Game Hosts
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_Individual Results_Hands]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[Individual Results] DROP CONSTRAINT FK_Individual Results_Hands
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_Individual Results_Players]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[Individual Results] DROP CONSTRAINT FK_Individual Results_Players
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_Actions_Individual Results]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[Actions] DROP CONSTRAINT FK_Actions_Individual Results
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_vol_put_money_in_Pot    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_vol_put_money_in_Pot]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_vol_put_money_in_Pot]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bets_won_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_bets_won_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_bets_won_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_seen    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_seen]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_seen]
GO

/****** Object:  Stored Procedure dbo.sp_delete_hand    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_delete_hand]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_delete_hand]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_calls    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_bet_calls]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_bet_calls]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_checked_to    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_bet_checked_to]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_bet_checked_to]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_folds    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_bet_folds]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_bet_folds]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_raises    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_bet_raises]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_bet_raises]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_then_raise    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_bet_then_raise]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_bet_then_raise]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bets    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_bets]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_bets]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bets_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_bets_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_bets_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bets_won_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_bets_won_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_bets_won_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_calls    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_calls]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_calls]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_check_checked_to    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_check_checked_to]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_check_checked_to]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_checked_to    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_checked_to]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_checked_to]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_checks    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_checks]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_checks]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_raises    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_raises]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_raises]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_raises_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_raises_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_raises_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_raises_won_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_raises_won_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_raises_won_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_flop_raise_turn_call    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_raise_turn_call]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_raise_turn_call]
GO

/****** Object:  Stored Procedure dbo.sp_flop_raise_turn_fold    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_raise_turn_fold]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_raise_turn_fold]
GO

/****** Object:  Stored Procedure dbo.sp_flop_raise_turn_raise    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_raise_turn_raise]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_raise_turn_raise]
GO

/****** Object:  Stored Procedure dbo.sp_num_flop_checks    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_num_flop_checks]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_num_flop_checks]
GO

/****** Object:  Stored Procedure dbo.sp_num_rsd_preflop_bet_rsd_flop    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_num_rsd_preflop_bet_rsd_flop]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_num_rsd_preflop_bet_rsd_flop]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_cards_open_called    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_cards_open_called]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_cards_open_called]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_cards_open_called_in_position    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_cards_open_called_in_position]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_cards_open_called_in_position]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_cards_open_raised    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_cards_open_raised]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_cards_open_raised]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_cards_open_raised_in_position    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_cards_open_raised_in_position]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_cards_open_raised_in_position]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_able_fold_steel    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_able_fold_steel]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_able_fold_steel]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_acted_first    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_acted_first]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_acted_first]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_acted_first_in_position    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_acted_first_in_position]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_acted_first_in_position]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_folded_to_steel    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_folded_to_steel]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_folded_to_steel]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_hands_raised    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_hands_raised]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_hands_raised]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_open_called_in_position    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_open_called_in_position]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_open_called_in_position]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_open_raised    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_open_raised]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_open_raised]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_open_raised_in_position    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_open_raised_in_position]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_open_raised_in_position]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_open_raised_steel    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_open_raised_steel]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_open_raised_steel]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_raised_saw_flop    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_raised_saw_flop]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_raised_saw_flop]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_actions    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_actions]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_actions]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_checked_to    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_bet_checked_to]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_bet_checked_to]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_raises    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_bet_raises]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_bet_raises]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_then_call    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_bet_then_call]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_bet_then_call]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_then_fold    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_bet_then_fold]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_bet_then_fold]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_then_raise    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_bet_then_raise]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_bet_then_raise]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bets    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_bets]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_bets]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bets_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_bets_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_bets_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_calls    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_calls]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_calls]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_check_checked_to    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_check_checked_to]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_check_checked_to]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_checked_to    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_checked_to]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_checked_to]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_checks    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_checks]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_checks]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_cr    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_cr]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_cr]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_folds    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_folds]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_folds]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_raises    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_raises]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_raises]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_raises_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_raises_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_raises_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_river_num_raises_won_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_river_num_raises_won_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_river_num_raises_won_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_actions    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_actions]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_actions]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_checked_to    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_bet_checked_to]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_bet_checked_to]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_raises    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_bet_raises]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_bet_raises]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_then_call    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_bet_then_call]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_bet_then_call]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_then_fold    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_bet_then_fold]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_bet_then_fold]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_then_raise    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_bet_then_raise]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_bet_then_raise]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bets    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_bets]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_bets]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bets_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_bets_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_bets_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bets_won_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_bets_won_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_bets_won_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_calls    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_calls]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_calls]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_check_checked_to    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_check_checked_to]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_check_checked_to]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_checked_to    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_checked_to]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_checked_to]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_checks    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_checks]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_checks]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_cr    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_cr]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_cr]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_folds    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_folds]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_folds]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_raises    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_raises]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_raises]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_raises_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_raises_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_raises_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_raises_won_showdown    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_raises_won_showdown]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_raises_won_showdown]
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_seen    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_num_seen]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_num_seen]
GO

/****** Object:  Stored Procedure dbo.sp_turn_raise_river_call    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_raise_river_call]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_raise_river_call]
GO

/****** Object:  Stored Procedure dbo.sp_turn_raise_river_fold    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_raise_river_fold]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_raise_river_fold]
GO

/****** Object:  Stored Procedure dbo.sp_turn_raise_river_raise    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_turn_raise_river_raise]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_turn_raise_river_raise]
GO

/****** Object:  Stored Procedure dbo.delete_data    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[delete_data]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[delete_data]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_actions    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_actions]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_actions]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_cr    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_cr]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_cr]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_folds    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_folds]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_folds]
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_seen    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_flop_num_seen]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_flop_num_seen]
GO

/****** Object:  Stored Procedure dbo.sp_get_hands    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_get_hands]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_get_hands]
GO

/****** Object:  Stored Procedure dbo.sp_num_actions    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_num_actions]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_num_actions]
GO

/****** Object:  Stored Procedure dbo.sp_num_bet_raises    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_num_bet_raises]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_num_bet_raises]
GO

/****** Object:  Stored Procedure dbo.sp_num_get_hands    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_num_get_hands]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_num_get_hands]
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_steel_pos    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_preflop_num_steel_pos]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_preflop_num_steel_pos]
GO

/****** Object:  View dbo.ActionsView    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[ActionsView]') and OBJECTPROPERTY(id, N'IsView') = 1)
drop view [dbo].[ActionsView]
GO

/****** Object:  View dbo.ResultsView    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[ResultsView]') and OBJECTPROPERTY(id, N'IsView') = 1)
drop view [dbo].[ResultsView]
GO

/****** Object:  View dbo.FirstActions    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FirstActions]') and OBJECTPROPERTY(id, N'IsView') = 1)
drop view [dbo].[FirstActions]
GO

/****** Object:  Table [dbo].[Actions]    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Actions]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Actions]
GO

/****** Object:  Table [dbo].[Individual Results]    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Individual Results]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Individual Results]
GO

/****** Object:  Table [dbo].[Hands]    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Hands]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Hands]
GO

/****** Object:  Table [dbo].[Players]    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Players]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Players]
GO

/****** Object:  Table [dbo].[Game Hosts]    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Game Hosts]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Game Hosts]
GO

/****** Object:  Table [dbo].[DataGrid]    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[DataGrid]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[DataGrid]
GO

/****** Object:  User Defined Datatype position    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.systypes where name = N'position')
exec sp_droptype N'position'
GO

/****** Object:  User Defined Datatype rank    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.systypes where name = N'rank')
exec sp_droptype N'rank'
GO

/****** Object:  User Defined Datatype suit    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.systypes where name = N'suit')
exec sp_droptype N'suit'
GO

/****** Object:  User Defined Datatype round_of_bets    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.systypes where name = N'round_of_bets')
exec sp_droptype N'round_of_bets'
GO

/****** Object:  Rule dbo.position_values    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[position_values]') and OBJECTPROPERTY(id, N'IsRule') = 1)
drop rule [dbo].[position_values]
GO

/****** Object:  Rule dbo.rank_values    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[rank_values]') and OBJECTPROPERTY(id, N'IsRule') = 1)
drop rule [dbo].[rank_values]
GO

/****** Object:  Rule dbo.suit_values    Script Date: 11/02/2003 2:40:54 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[suit_values]') and OBJECTPROPERTY(id, N'IsRule') = 1)
drop rule [dbo].[suit_values]
GO

/****** Object:  Rule dbo.position_values    Script Date: 11/02/2003 2:40:55 PM ******/

/****** Object:  Rule dbo.position_values    Script Date: 20/04/00 20:17:30 ******/
create rule [position_values] as 0 <= @position AND @position <=10

GO

/****** Object:  Rule dbo.rank_values    Script Date: 11/02/2003 2:40:55 PM ******/

/****** Object:  Rule dbo.rank_values    Script Date: 20/04/00 20:17:30 ******/
create rule [rank_values] as 0 <= @rank AND @rank <= 14

GO

/****** Object:  Rule dbo.suit_values    Script Date: 11/02/2003 2:40:55 PM ******/

/****** Object:  Rule dbo.suit_values    Script Date: 20/04/00 20:17:30 ******/
create rule [suit_values] as @suit in (0, 1,2,3,4)

GO

/****** Object:  User Defined Datatype round_of_bets    Script Date: 11/02/2003 2:40:55 PM ******/
setuser
GO

EXEC sp_addtype N'round_of_bets', N'smallint', N'not null'
GO

setuser
GO

/****** Object:  User Defined Datatype position    Script Date: 11/02/2003 2:40:55 PM ******/
setuser
GO

EXEC sp_addtype N'position', N'tinyint', N'not null'
GO

setuser
GO

setuser
GO

EXEC sp_bindrule N'[dbo].[position_values]', N'[position]'
GO

setuser
GO

/****** Object:  User Defined Datatype rank    Script Date: 11/02/2003 2:40:55 PM ******/
setuser
GO

EXEC sp_addtype N'rank', N'tinyint', N'not null'
GO

setuser
GO

setuser
GO

EXEC sp_bindrule N'[dbo].[rank_values]', N'[rank]'
GO

setuser
GO

/****** Object:  User Defined Datatype suit    Script Date: 11/02/2003 2:40:55 PM ******/
setuser
GO

EXEC sp_addtype N'suit', N'tinyint', N'not null'
GO

setuser
GO

setuser
GO

EXEC sp_bindrule N'[dbo].[suit_values]', N'[suit]'
GO

setuser
GO

/****** Object:  Table [dbo].[DataGrid]    Script Date: 11/02/2003 2:40:55 PM ******/
CREATE TABLE [dbo].[DataGrid] (
	[Data Colum Id] [smallint] IDENTITY (1, 1) NOT NULL ,
	[Grid Number] [tinyint] NOT NULL ,
	[Colum Number] [tinyint] NOT NULL ,
	[Type] [tinyint] NULL ,
	[Header] [varchar] (10) NULL ,
	[Tooltip] [varchar] (50) NULL ,
	[Help] [varchar] (50) NULL ,
	[SP Count Numerator] [varchar] (50) NULL ,
	[SP Count Denonator] [varchar] (50) NULL ,
	[SP Numerator List] [varchar] (50) NULL ,
	[SP Denominator List] [varchar] (50) NULL ,
	[Dont show] [tinyint] NULL ,
	[Italic] [smallint] NULL ,
	[Normal] [smallint] NULL ,
	[Bold] [smallint] NULL ,
	[Underline] [smallint] NULL ,
	[Avearage Value] [smallint] NULL ,
	[Variance] [smallint] NULL ,
	[Axis] [tinyint] NULL ,
	[SP Count Denonator2] [varchar] (50) NULL ,
	[SP Count Denonator3] [varchar] (50) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[Game Hosts]    Script Date: 11/02/2003 2:40:56 PM ******/
CREATE TABLE [dbo].[Game Hosts] (
	[Host Id] [smallint] IDENTITY (1, 1) NOT NULL ,
	[Host Name] [char] (100) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[Hands]    Script Date: 11/02/2003 2:40:56 PM ******/
CREATE TABLE [dbo].[Hands] (
	[Hand Id] [int] IDENTITY (1, 1) NOT NULL ,
	[FKH_Poker site] [smallint] NOT NULL ,
	[Small bet] [int] NULL ,
	[Big bet] [int] NULL ,
	[Ante] [int] NULL ,
	[Hand reference] [int] NOT NULL ,
	[Date] [datetime] NULL ,
	[Variant] [smallint] NULL ,
	[Pot] [smallint] NULL ,
	[Rake] [tinyint] NULL ,
	[Flop card 1 rank] [rank] NULL ,
	[Flop card 1 suit] [suit] NULL ,
	[Flop card 2 rank] [rank] NULL ,
	[Flop card 2 suit] [suit] NULL ,
	[Flop card 3 rank] [rank] NULL ,
	[Flop card 3 suit] [suit] NULL ,
	[Turn rank] [rank] NULL ,
	[Turn suit] [suit] NULL ,
	[River rank] [rank] NULL ,
	[River suit] [suit] NULL ,
	[Active Players] [tinyint] NULL ,
	[Table name] [varchar] (50) NULL ,
	[Incomplete] [smallint] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[Players]    Script Date: 11/02/2003 2:40:56 PM ******/
CREATE TABLE [dbo].[Players] (
	[Player Id] [int] IDENTITY (1, 1) NOT NULL ,
	[FK_Host Id] [smallint] NOT NULL ,
	[Nick] [varchar] (50) NOT NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[Individual Results]    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE TABLE [dbo].[Individual Results] (
	[Individual Results Id] [int] IDENTITY (1, 1) NOT NULL ,
	[FK_Hand Id] [int] NOT NULL ,
	[FK_Player Id] [int] NOT NULL ,
	[Position] [position] NULL ,
	[Win loss] [smallint] NULL ,
	[First Card Rank] [rank] NULL ,
	[First Card Suit] [suit] NULL ,
	[Second Card Rank] [rank] NULL ,
	[Second Card Suit] [suit] NULL ,
	[Chips] [int] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[Actions]    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE TABLE [dbo].[Actions] (
	[Action Id] [int] IDENTITY (1, 1) NOT NULL ,
	[FK_Results Id] [int] NOT NULL ,
	[Action] [smallint] NOT NULL ,
	[Amount] [int] NULL ,
	[Round] [smallint] NOT NULL 
) ON [PRIMARY]
GO

ALTER TABLE [dbo].[Actions] WITH NOCHECK ADD 
	CONSTRAINT [PK_Actions] PRIMARY KEY  CLUSTERED 
	(
		[Action Id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[Game Hosts] WITH NOCHECK ADD 
	CONSTRAINT [PK_Game Hosts] PRIMARY KEY  NONCLUSTERED 
	(
		[Host Id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[Hands] WITH NOCHECK ADD 
	CONSTRAINT [PK_Hands] PRIMARY KEY  NONCLUSTERED 
	(
		[Hand Id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[Players] WITH NOCHECK ADD 
	CONSTRAINT [PK_Players] PRIMARY KEY  NONCLUSTERED 
	(
		[Player Id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[Individual Results] WITH NOCHECK ADD 
	CONSTRAINT [DF_Individual Results_Win loss] DEFAULT (0) FOR [Win loss],
	CONSTRAINT [PK_Individual Results] PRIMARY KEY  NONCLUSTERED 
	(
		[Individual Results Id]
	)  ON [PRIMARY] 
GO

setuser
GO

EXEC sp_bindrule N'[dbo].[rank_values]', N'[Hands].[Flop card 1 rank]'
GO

EXEC sp_bindrule N'[dbo].[suit_values]', N'[Hands].[Flop card 1 suit]'
GO

EXEC sp_bindrule N'[dbo].[rank_values]', N'[Hands].[Flop card 2 rank]'
GO

EXEC sp_bindrule N'[dbo].[suit_values]', N'[Hands].[Flop card 2 suit]'
GO

EXEC sp_bindrule N'[dbo].[rank_values]', N'[Hands].[Flop card 3 rank]'
GO

EXEC sp_bindrule N'[dbo].[suit_values]', N'[Hands].[Flop card 3 suit]'
GO

EXEC sp_bindrule N'[dbo].[rank_values]', N'[Hands].[River rank]'
GO

EXEC sp_bindrule N'[dbo].[suit_values]', N'[Hands].[River suit]'
GO

EXEC sp_bindrule N'[dbo].[rank_values]', N'[Hands].[Turn rank]'
GO

EXEC sp_bindrule N'[dbo].[suit_values]', N'[Hands].[Turn suit]'
GO

setuser
GO

setuser
GO

EXEC sp_bindrule N'[dbo].[rank_values]', N'[Individual Results].[First Card Rank]'
GO

EXEC sp_bindrule N'[dbo].[suit_values]', N'[Individual Results].[First Card Suit]'
GO

EXEC sp_bindrule N'[dbo].[position_values]', N'[Individual Results].[Position]'
GO

EXEC sp_bindrule N'[dbo].[rank_values]', N'[Individual Results].[Second Card Rank]'
GO

EXEC sp_bindrule N'[dbo].[suit_values]', N'[Individual Results].[Second Card Suit]'
GO

setuser
GO

ALTER TABLE [dbo].[Hands] ADD 
	CONSTRAINT [FK_Hands_Game Hosts] FOREIGN KEY 
	(
		[FKH_Poker site]
	) REFERENCES [dbo].[Game Hosts] (
		[Host Id]
	)
GO

ALTER TABLE [dbo].[Players] ADD 
	CONSTRAINT [FK_Players_Game Hosts] FOREIGN KEY 
	(
		[FK_Host Id]
	) REFERENCES [dbo].[Game Hosts] (
		[Host Id]
	)
GO

ALTER TABLE [dbo].[Individual Results] ADD 
	CONSTRAINT [FK_Individual Results_Hands] FOREIGN KEY 
	(
		[FK_Hand Id]
	) REFERENCES [dbo].[Hands] (
		[Hand Id]
	),
	CONSTRAINT [FK_Individual Results_Players] FOREIGN KEY 
	(
		[FK_Player Id]
	) REFERENCES [dbo].[Players] (
		[Player Id]
	)
GO

ALTER TABLE [dbo].[Actions] ADD 
	CONSTRAINT [FK_Actions_Individual Results] FOREIGN KEY 
	(
		[FK_Results Id]
	) REFERENCES [dbo].[Individual Results] (
		[Individual Results Id]
	)
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  View dbo.FirstActions    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  VIEW dbo.FirstActions
AS
SELECT     Hero.*
FROM         dbo.ActionsView Hero
WHERE     ([Action Id] =
                          (SELECT     MIN(Nest.[Action id])
                            FROM          ActionsView Nest
                            WHERE      Nest.[Hand id] = Hero.[Hand id] AND Nest.[Player id] = Hero.[player id] AND Nest.[Round] = 1))


GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  View dbo.ResultsView    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  VIEW dbo.ResultsView
AS
SELECT     dbo.[Game Hosts].*, dbo.Hands.*, dbo.[Individual Results].*, dbo.Players.*
FROM         dbo.[Game Hosts] INNER JOIN
                      dbo.Hands ON dbo.[Game Hosts].[Host Id] = dbo.Hands.[FKH_Poker site] INNER JOIN
                      dbo.[Individual Results] ON dbo.Hands.[Hand Id] = dbo.[Individual Results].[FK_Hand Id] INNER JOIN
                      dbo.Players ON dbo.[Game Hosts].[Host Id] = dbo.Players.[FK_Host Id] AND dbo.[Individual Results].[FK_Player Id] = dbo.Players.[Player Id]


GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  View dbo.ActionsView    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  VIEW dbo.ActionsView
AS
SELECT     dbo.Actions.*, dbo.[Game Hosts].*, dbo.Hands.*, dbo.[Individual Results].*, dbo.Players.*
FROM         dbo.Hands INNER JOIN
                      dbo.[Game Hosts] ON dbo.Hands.[FKH_Poker site] = dbo.[Game Hosts].[Host Id] INNER JOIN
                      dbo.[Individual Results] ON dbo.Hands.[Hand Id] = dbo.[Individual Results].[FK_Hand Id] INNER JOIN
                      dbo.Actions ON dbo.[Individual Results].[Individual Results Id] = dbo.Actions.[FK_Results Id] INNER JOIN
                      dbo.Players ON dbo.[Game Hosts].[Host Id] = dbo.Players.[FK_Host Id] AND dbo.[Individual Results].[FK_Player Id] = dbo.Players.[Player Id]


GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.delete_data    Script Date: 11/02/2003 2:40:57 PM ******/

/****** Object:  Stored Procedure dbo.delete_data    Script Date: 20/04/00 20:17:34 ******/
CREATE PROCEDURE delete_data AS

DELETE FROM [Individual Results]
DELETE FROM Hands
DELETE FROM Players




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_actions    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_flop_actions
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_cr    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_cr_flop
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(distinct FirstAct.[Hand id])
from ActionsView FirstAct, ActionsView SecondAct 
where
FirstAct.[player id] = @NickId
AND FirstAct.[player id] = SecondAct.[player id]
AND FirstAct.[Host id] = @host_id
AND FirstAct.[Hand id] = SecondAct.[Hand id]
AND FirstAct.[Round] = 2
AND SecondAct.[Round] = 2
AND FirstAct.[Action] = 4
AND SecondAct.[Action] = 7

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_folds    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_flop_folds
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[Action] = 3
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_seen    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_flops_seen
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(distinct ActionsView.[Hand id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_get_hands    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE PROCEDURE sp_get_hands
@nick varchar(50),
@host_id int
 AS

SELECT 
ResultsView.[Hand Id] 
FROM  ResultsView
WHERE
ResultsView.Nick = @nick
AND ResultsView.[Host Id] = @host_id
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_num_actions    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_actions
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS

declare @NickId int
select @NickId = [player id] from Players where nick =@nick

select
count(distinct [action id])
from ActionsView 
where
[player id] = @NickId
AND [Host id] = @host_id
AND Variant = Variant
AND [date] > @Date

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_num_bet_raises    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_bet_raises
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS

declare @NickId int
select @NickId = [player id] from Players where nick =@nick

select
count(distinct [action id])
from ActionsView 
where
[player id] = @NickId
AND [Host id] = @host_id
AND Variant = Variant
AND [date] > @Date
aND [action] in (6,7)
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_num_get_hands    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_get_hands
@nick varchar(50),
@host_id int
 AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

SELECT 
Count([ResultsView].[Hand Id])  AS Number
FROM  ResultsView
WHERE
[ResultsView].[player id] =  @NickId
AND [ResultsView].[Host Id] = @host_id
AND [ResultsView].Position <> null
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_steel_pos    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_steel_pos_pf
@nick varchar(50),
@host_id int
 AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(h.[hand id])
from ActionsView h
where
h.[player id]= @NickId
AND h.[Host id] = @host_id
AND (	h.[Position] >= h.[Active players] - 1
	OR h.[Position] = 2)
AND h.[action id] =
(
	select 
	min(Nest.[Action id])
	from ActionsView Nest
	where 
	Nest.[Hand id] = H.[hand id]
	AND Nest.[Player id] = h.[player id]
)
AND h.[hand id] not in
(
	select 
	hero.[hand id]
	from ActionsView Hero, ActionsView Others
	where 
	Hero.[Host id] = @host_id
	AND Hero.[player id]= @NickId
	AND Others.[player id] <> @NickId
	
	AND Hero.[Hand id] = Others.[hand id]
	
	AND Others.[Action] in (0,1,4,5,6,7,8)
	AND Others.[Action Id] < Hero.[Action id]
	AND Hero.[Action id] = 
	(
		select 
		min(Nest.[Action id])
		from ActionsView Nest
		where 
		Nest.[Hand id] = Hero.[Hand id]
		AND Nest.[Player id] = Hero.[player id]
	)
	
	group by Hero.[Action id], hero.[hand id] 
)
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_calls    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE  sp_flop_num_bet_calls
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 2
AND SecondAction.[Round] = 2
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 6 
AND SecondAction.[Action] = 5
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_checked_to    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE sp_flop_num_bet_checked_to
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select
count (distinct hero.[Hand id])
from ActionsView hero, ActionsView other
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[Round] = 2
AND hero.[action] = 6
AND hero.Variant = @Variant
AND hero.[date] > @Date
AND hero.[Hand id] = other.[Hand id]
AND hero.[Action id] = other.[Action id] - 1
AND hero.[Position] > other.[Position]


GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_folds    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE  sp_flop_num_bet_folds
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 2
AND SecondAction.[Round] = 2
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 6 
AND SecondAction.[Action] = 3
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_raises    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE sp_flop_num_bet_raises
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[ACtion] in (6,7)

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bet_then_raise    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE  sp_flop_num_bet_then_raise
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 2
AND SecondAction.[Round] = 2
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 6 
AND SecondAction.[Action] = 7
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bets    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_flop_num_bets
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[ACtion] = 6
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bets_showdown    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE  sp_flop_num_bets_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[Action] = 6
AND ActionsView.[First Card Rank] > 0
AND Variant = @Variant
AND [date] > @Date
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_bets_won_showdown    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE PROCEDURE  sp_flop_num_bets_won_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[Action] = 6
AND ActionsView.[First Card Rank]> 0
AND ActionsView.[Win Loss] > 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_calls    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_flop_calls
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[ACtion] = 5
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_check_checked_to    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_flop_num_check_checked_to
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select
count (distinct hero.[Hand id])
from ActionsView hero, ActionsView other
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[Round] = 2
AND hero.[action] = 4
AND hero.Variant = @Variant
AND hero.[date] > @Date
AND hero.[Hand id] = other.[Hand id]
AND hero.[Action id] = other.[Action id] - 1
AND hero.[Position] > other.[Position]

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_checked_to    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE sp_flop_num_checked_to
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select
count (distinct hero.[Hand id])
from ActionsView hero
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[Round] = 2
AND hero.Variant = Variant
AND hero.[date] > @Date
AND 
(
	select count(distinct EarlerChecks.[player id])
	from ActionsView EarlerChecks
	where 
	EarlerChecks.[hand id] = hero.[hand id]
	AND EarlerChecks.[action] = 4
	AND EarlerChecks.[round] = 2
	AND EarlerChecks.[action id] < hero.[action id]
	AND EarlerChecks.[player id] <>  @NickId
) 
	=
(
	select count(distinct ActivePlayers.[player id])
	from ActionsView ActivePlayers
	where
	ActivePlayers.[hand id] = hero.[hand id]
	AND ActivePlayers.[round] = 2
	AND ActivePlayers.[player id] <> @NickId
)	

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_checks    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE  sp_flop_num_checks
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[ACtion] =4




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_raises    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_flop_num_raises
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[ACtion] = 7
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_raises_showdown    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE PROCEDURE  sp_flop_num_raises_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[Action] = 7
AND ActionsView.[First Card Rank]> 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_num_raises_won_showdown    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE PROCEDURE  sp_flop_num_raises_won_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[Action] = 7
AND ActionsView.[First Card Rank]> 0
AND ActionsView.[Win Loss] > 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_raise_turn_call    Script Date: 11/02/2003 2:40:57 PM ******/


CREATE   PROCEDURE  sp_flop_raise_turn_call
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(distinct FirstAction.[hand id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 2
AND SecondAction.[Round] = 3
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 7 
AND SecondAction.[Action] = 5
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date





GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_raise_turn_fold    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE  sp_flop_raise_turn_fold
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 2
AND SecondAction.[Round] = 3
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 7 
AND SecondAction.[Action] = 3
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_flop_raise_turn_raise    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE  sp_flop_raise_turn_raise
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 2
AND SecondAction.[Round] = 3
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 7 
AND SecondAction.[Action] = 7
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_num_flop_checks    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE  sp_num_flop_checks
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 2
AND ActionsView.[ACtion] =4




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_num_rsd_preflop_bet_rsd_flop    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE sp_num_rsd_preflop_bet_rsd_flop
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS

declare @NickId int
select @NickId = [player id] from Players where nick =@nick

select
count (distinct heroPreflop.[Hand id])
from ActionsView heroPreflop, ActionsView heroFlop
where
heroPreflop.[player id] = @NickId
AND heroPreflop.[Host id] = @host_id
AND heroPreflop.[Round] = 1
AND heroPreflop.[action] = 7
AND heroFlop.[Round] = 2
AND heroFlop.[action] in (6,7)
AND heroPreflop.Variant = @Variant
AND heroPreflop.[date] > @Date
AND heroPreflop.[Hand id] = heroFlop.[Hand id]
AND heroPreflop.[player id] = heroFlop.[player id]


GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_cards_open_called    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_preflop_cards_open_called
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select 
[First Card Rank], [First Card Suit],
[Second Card Rank], [Second Card Suit], [Position]
from FirstActions 
where 
[Host id] = @host_id
AND [player id] = @NickId
AND [First Card Rank] >= 0
AND [Action] = 5
AND Variant = @Variant
AND [date] > @Date
AND [Hand id] not in 
(
	select Hero.[Hand Id]
	from FirstActions Hero, FirstActions Others
	where
	Hero.[player id] = @NickId
	AND Others.[player id] <> @NickId
	AND Hero.[Hand Id] = Others.[Hand Id]
	AND Hero.[Action ID] > Others.[Action Id]
	AND Others.[Action] > 3
)

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_cards_open_called_in_position    Script Date: 11/02/2003 2:40:57 PM ******/



CREATE    PROCEDURE sp_preflop_cards_open_called_in_position
@nick varchar(50),
@host_id int,
@position int,
@Variant int = 0,
@Date datetime = '1962'
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select 
[First Card Rank], [First Card Suit],
[Second Card Rank], [Second Card Suit]
from FirstActions 
where 
[Host id] = @host_id
AND [player id] = @NickId
AND [First Card Rank] >= 0
AND [Position] = @position
AND [Action] = 5
AND Variant = @Variant
AND [date] > @Date
AND [Hand id] not in 
(
	select Hero.[Hand Id]
	from FirstActions Hero, FirstActions Others
	where
	Hero.[player id] = @NickId
	AND Others.[player id] <> @NickId
	AND Hero.[Hand Id] = Others.[Hand Id]
	AND Hero.[Action ID] > Others.[Action Id]
	AND Others.[Action] > 3
)



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_cards_open_raised    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_preflop_cards_open_raised
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select 
[First Card Rank], [First Card Suit],
[Second Card Rank], [Second Card Suit], [Position],
[Hand id]
from FirstActions 
where 
[Host id] = @host_id
AND [player id] = @NickId
AND [First Card Rank] >= 0
AND [Action] = 7
AND Variant = @Variant
AND [date] > @Date
AND [Hand id] not in 
(
	select Hero.[Hand Id]
	from FirstActions Hero, FirstActions Others
	where
	Hero.[player id] = @NickId
	AND Others.[player id] <> @NickId
	AND Hero.[Hand Id] = Others.[Hand Id]
	AND Hero.[Action ID] > Others.[Action Id]
	AND Others.[Action] > 3
)
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_cards_open_raised_in_position    Script Date: 11/02/2003 2:40:57 PM ******/




CREATE     PROCEDURE sp_preflop_cards_open_raised_in_position
@nick varchar(50),
@host_id int,
@position int,
@Variant int = 0,
@Date datetime = '1962'
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select 
[First Card Rank], [First Card Suit],
[Second Card Rank], [Second Card Suit],
[Hand id]
from FirstActions 
where 
[Host id] = @host_id
AND [player id] = @NickId
AND [First Card Rank] >= 0
AND [Position] = @position
AND [Action] = 7
AND Variant = @Variant
AND [date] > @Date
AND [Hand id] not in 
(
	select Hero.[Hand Id]
	from FirstActions Hero, FirstActions Others
	where
	Hero.[player id] = @NickId
	AND Others.[player id] <> @NickId
	AND Hero.[Hand Id] = Others.[Hand Id]
	AND Hero.[Action ID] > Others.[Action Id]
	AND Others.[Action] > 3
)




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_able_fold_steel    Script Date: 11/02/2003 2:40:57 PM ******/


CREATE   PROCEDURE sp_preflop_num_able_fold_steel
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(distinct (hero.[hand id]))
from ActionsView hero, ActionsView other
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[hand id] = other.[hand id]
AND other.[action id] < hero.[action id]
AND other.[action] = 7
AND hero.[position] = 2
AND hero.[Round] = 1
AND (other.[position] = 1 OR other.[position] >= other.[active players] -1)



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_acted_first    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE sp_preflop_num_acted_first
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select 
count(*)
from FirstActions 
where 
[Host id] = @host_id
AND [player id] = @NickId
AND Variant = @Variant
AND [date] > @Date
AND [Hand id] not in 
(
	select Hero.[Hand Id]
	from FirstActions Hero, FirstActions Others
	where
	Hero.[player id] = @NickId
	AND Others.[player id] <> @NickId
	AND Hero.[Hand Id] = Others.[Hand Id]
	AND Hero.[Action ID] > Others.[Action Id]
	AND Others.[Action] > 3
)

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_acted_first_in_position    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE sp_preflop_num_acted_first_in_position
@nick varchar(50),
@host_id int,
@postion int,
@Variant int = 0,
@Date datetime = '1962'
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select 
count(*)
from FirstActions 
where 
[Host id] = @host_id
AND [player id] = @NickId
AND [Position] = @postion
AND Variant = @Variant
AND [date] > @Date
AND [Hand id] not in 
(
	select Hero.[Hand Id]
	from FirstActions Hero, FirstActions Others
	where
	Hero.[player id] = @NickId
	AND Others.[player id] <> @NickId
	AND Hero.[Hand Id] = Others.[Hand Id]
	AND Hero.[Action ID] > Others.[Action Id]
	AND Others.[Action] > 3
)


GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_folded_to_steel    Script Date: 11/02/2003 2:40:57 PM ******/


CREATE   PROCEDURE sp_preflop_num_folded_to_steel
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select
count(distinct (hero.[hand id]))
from ActionsView hero, ActionsView other
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[hand id] = other.[hand id]
AND other.[action id] < hero.[action id]
AND hero.[action] = 3
AND other.[action] = 7
AND hero.[position] = 2
AND hero.[Round] = 1
AND (other.[position] = 1 OR other.[position] >= other.[active players] -1)



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_hands_raised    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_hands_raised_prefolop
@nick varchar(50),
@host_id int
 AS

declare @NickId int
select @NickId = [player id] from Players where nick =@nick

select
count(distinct [hand id])
from ActionsView
where
[player id] = @NickId
AND [Host id] = @host_id
AND [Round] = 1
AND [Action] = 7
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_open_called_in_position    Script Date: 11/02/2003 2:40:57 PM ******/


CREATE   PROCEDURE sp_preflop_num_open_called_in_position
@nick varchar(50),
@host_id int,
@position int,
@Variant int = 0,
@Date datetime = '1962'
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select 
count(*)
from FirstActions 
where 
[Host id] = @host_id
AND [player id] = @NickId
AND [First Card Rank] >= 0
AND [Position] = @position
AND [Action] = 5
AND Variant = @Variant
AND [date] > @Date
AND [Hand id] not in 
(
	select Hero.[Hand Id]
	from FirstActions Hero, FirstActions Others
	where
	Hero.[player id] = @NickId
	AND Others.[player id] <> @NickId
	AND Hero.[Hand Id] = Others.[Hand Id]
	AND Hero.[Action ID] > Others.[Action Id]
	AND Others.[Action] > 3
)


GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_open_raised    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_count_open_raised_preflop
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select 
count(*)
from FirstActions Hero
where 
Hero.[Host id] = @host_id
AND Hero.[player id] = @NickId
AND Hero.[Position] = 3
AND Hero.[First Card Rank] >= 0
AND [Hand id] not in 
(
	select [Hand Id]
	from FirstActions Others
	where
	Hero.[Action ID] > Others.[Action Id]
	AND Others.[Action] > 3
)
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_open_raised_in_position    Script Date: 11/02/2003 2:40:57 PM ******/


CREATE   PROCEDURE sp_preflop_num_open_raised_in_position
@nick varchar(50),
@host_id int,
@position int,
@Variant int = 0,
@Date datetime = '1962'
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select 
count(*)
from FirstActions 
where 
[Host id] = @host_id
AND [player id] = @NickId
AND [First Card Rank] >= 0
AND [Position] = @position
AND [Action] = 7
AND Variant = @Variant
AND [date] > @Date
AND [Hand id] not in 
(
	select Hero.[Hand Id]
	from FirstActions Hero, FirstActions Others
	where
	Hero.[player id] = @NickId
	AND Others.[player id] <> @NickId
	AND Hero.[Hand Id] = Others.[Hand Id]
	AND Hero.[Action ID] > Others.[Action Id]
	AND Others.[Action] > 3
)


GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_open_raised_steel    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_open_raised_steel_pf
@nick varchar(50),
@host_id int
 AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(h.[hand id])
from ActionsView h
where
h.[player id]= @NickId
AND h.[Host id] = @host_id
AND h.[action] = 7
AND (	h.[Position] >= h.[Active players] - 1
	OR h.[Position] = 2)
AND h.[action id] =
(
	select 
	min(Nest.[Action id])
	from ActionsView Nest
	where 
	Nest.[Hand id] = H.[hand id]
	AND Nest.[Player id] = h.[player id]
)
AND h.[hand id] not in
(
	select 
	hero.[hand id]
	from ActionsView Hero, ActionsView Others
	where 
	Hero.[Host id] = @host_id
	AND Hero.[player id]= @NickId
	AND Others.[player id] <> @NickId
	
	AND Hero.[Hand id] = Others.[hand id]
	
	AND Others.[Action] in (0,1,4,5,6,7,8)
	AND Others.[Action Id] < Hero.[Action id]
	AND Hero.[Action id] = 
	(
		select 
		min(Nest.[Action id])
		from ActionsView Nest
		where 
		Nest.[Hand id] = Hero.[Hand id]
		AND Nest.[Player id] = Hero.[player id]
	)
	
	group by Hero.[Action id], hero.[hand id] 
)
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_raised_saw_flop    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE sp_preflop_num_raised_saw_flop
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS

declare @NickId int
select @NickId = [player id] from Players where nick =@nick

select
count (distinct heroPreflop.[Hand id])
from ActionsView heroPreflop, ActionsView heroFlop
where
heroPreflop.[player id] = @NickId
AND heroPreflop.[Host id] = @host_id
AND heroPreflop.[Round] = 1
AND heroPreflop.[action] = 7
AND heroFlop.[Round] = 2
AND heroPreflop.Variant = @Variant
AND heroPreflop.[date] > @Date
AND heroPreflop.[Hand id] = heroFlop.[Hand id]
AND heroPreflop.[player id] = heroFlop.[player id]

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_actions    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_num_river_actions
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_checked_to    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE sp_river_num_bet_checked_to
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count (distinct hero.[Hand id])
from ActionsView hero, ActionsView other
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[Round] = 4
AND hero.[action] = 6
AND hero.Variant = @Variant
AND hero.[date] > @Date
AND hero.[Hand id] = other.[Hand id]
AND hero.[Action id] = other.[Action id] - 1
AND hero.[Position] > other.[Position]







GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_raises    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE sp_river_num_bet_raises
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[ACtion] in (6,7)






GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_then_call    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE  sp_river_num_bet_then_call
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 4
AND SecondAction.[Round] = 4
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 6 
AND SecondAction.[Action] = 5
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_then_fold    Script Date: 11/02/2003 2:40:57 PM ******/

CREATE  PROCEDURE  sp_river_num_bet_then_fold
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 4
AND SecondAction.[Round] = 4
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 6 
AND SecondAction.[Action] = 3
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bet_then_raise    Script Date: 11/02/2003 2:40:57 PM ******/



CREATE    PROCEDURE  sp_river_num_bet_then_raise
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(distinct FirstAction.[hand id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 4
AND SecondAction.[Round] = 4
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 6 
AND SecondAction.[Action] = 7
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date






GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bets    Script Date: 11/02/2003 2:40:57 PM ******/
CREATE PROCEDURE sp_river_num_bets
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[ACtion] = 6
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bets_showdown    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE PROCEDURE  sp_river_num_bets_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[Action] = 6
AND ActionsView.[First Card Rank]> 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_calls    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_river_calls
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[ACtion] = 5

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_check_checked_to    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE  PROCEDURE sp_river_num_check_checked_to
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select
count (distinct hero.[Hand id])
from ActionsView hero, ActionsView other
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[Round] = 4
AND hero.[action] = 4
AND hero.Variant = @Variant
AND hero.[date] > @Date
AND hero.[Hand id] <> other.[Hand id]
AND hero.[Action id] = other.[Action id] - 1

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_checked_to    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_checked_to_river
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select
count (distinct hero.[Hand id])
from ActionsView hero
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[Round] = 4
AND hero.Variant = Variant
AND hero.[date] > @Date
AND 
(
	select count(distinct EarlerChecks.[player id])
	from ActionsView EarlerChecks
	where 
	EarlerChecks.[hand id] = hero.[hand id]
	AND EarlerChecks.[action] = 4
	AND EarlerChecks.[round] = 4
	AND EarlerChecks.[action id] < hero.[action id]
	AND EarlerChecks.[player id] <>  @NickId
) 
	=
(
	select count(distinct ActivePlayers.[player id])
	from ActionsView ActivePlayers
	where
	ActivePlayers.[hand id] = hero.[hand id]
	AND ActivePlayers.[round] = 4
	AND ActivePlayers.[player id] <> @NickId
)	

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_checks    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE  sp_river_num_checks
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[ACtion] =4




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_cr    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_cr_river
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(distinct FirstAct.[Hand id])
from ActionsView FirstAct, ActionsView SecondAct 
where
FirstAct.[player id] = @NickId
AND FirstAct.[player id] = SecondAct.[player id]
AND FirstAct.[Host id] = @host_id
AND FirstAct.[Hand id] = SecondAct.[Hand id]
AND FirstAct.[Round] = 4
AND SecondAct.[Round] = 4
AND FirstAct.[Action] = 4
AND SecondAct.[Action] = 7







GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_folds    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_river_folds
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[Action] = 3




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_raises    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_river_num_raises
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[ACtion] = 7
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_raises_showdown    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE PROCEDURE  sp_river_num_raises_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[Action] = 7
AND ActionsView.[First Card Rank]> 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_raises_won_showdown    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE PROCEDURE  sp_river_num_raises_won_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[Action] = 7
AND ActionsView.[First Card Rank]> 0
AND ActionsView.[Win Loss] > 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_actions    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_turn_actions
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_checked_to    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE  PROCEDURE sp_turn_num_bet_checked_to
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count (distinct hero.[Hand id])
from ActionsView hero, ActionsView other
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[Round] = 3
AND hero.[action] = 6
AND hero.Variant = @Variant
AND hero.[date] > @Date
AND hero.[Hand id] = other.[Hand id]
AND hero.[Action id] = other.[Action id] - 1
AND hero.[Position] > other.[Position]







GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_raises    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE  PROCEDURE sp_turn_num_bet_raises
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[ACtion] in (6,7)






GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_then_call    Script Date: 11/02/2003 2:40:58 PM ******/


CREATE   PROCEDURE  sp_turn_num_bet_then_call
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 3
AND SecondAction.[Round] = 3
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 6 
AND SecondAction.[Action] = 5
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date





GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_then_fold    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE  PROCEDURE  sp_turn_num_bet_then_fold
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 3
AND SecondAction.[Round] = 3
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 6 
AND SecondAction.[Action] = 3
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bet_then_raise    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE  PROCEDURE  sp_turn_num_bet_then_raise
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 3
AND SecondAction.[Round] = 3
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 6 
AND SecondAction.[Action] = 7
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bets    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_turn_num_bets
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[ACtion] = 6
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bets_showdown    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE PROCEDURE  sp_turn_num_bets_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[Action] = 6
AND ActionsView.[First Card Rank]> 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_bets_won_showdown    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE PROCEDURE  sp_turn_num_bets_won_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[Action] = 6
AND ActionsView.[First Card Rank]> 0
AND ActionsView.[Win Loss] > 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_calls    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_turn_calls
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[ACtion] = 5

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_check_checked_to    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_turn_num_check_checked_to
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select
count (distinct hero.[Hand id])
from ActionsView hero, ActionsView other
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[Round] = 3
AND hero.[action] = 4
AND hero.Variant = @Variant
AND hero.[date] > @Date
AND hero.[Hand id] = other.[Hand id]
AND hero.[Action id] = other.[Action id] - 1
AND hero.[Position] > other.[Position]

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_checked_to    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_checked_to_turn
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick


select
count (distinct hero.[Hand id])
from ActionsView hero
where
hero.[player id] = @NickId
AND hero.[Host id] = @host_id
AND hero.[Round] = 3
AND hero.Variant = Variant
AND hero.[date] > @Date
AND 
(
	select count(distinct EarlerChecks.[player id])
	from ActionsView EarlerChecks
	where 
	EarlerChecks.[hand id] = hero.[hand id]
	AND EarlerChecks.[action] = 4
	AND EarlerChecks.[round] = 3
	AND EarlerChecks.[action id] < hero.[action id]
	AND EarlerChecks.[player id] <>  @NickId
) 
	=
(
	select count(distinct ActivePlayers.[player id])
	from ActionsView ActivePlayers
	where
	ActivePlayers.[hand id] = hero.[hand id]
	AND ActivePlayers.[round] = 3
	AND ActivePlayers.[player id] <> @NickId
)	

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_checks    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE  sp_turn_num_checks
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[ACtion] =4




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_cr    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_cr_turn
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(distinct FirstAct.[Hand id])
from ActionsView FirstAct, ActionsView SecondAct 
where
FirstAct.[player id] = @NickId
AND FirstAct.[player id] = SecondAct.[player id]
AND FirstAct.[Host id] = @host_id
AND FirstAct.[Hand id] = SecondAct.[Hand id]
AND FirstAct.[Round] = 3
AND SecondAct.[Round] = 3
AND FirstAct.[Action] = 4
AND SecondAct.[Action] = 7







GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_folds    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_turn_folds
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[Action] = 3




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_raises    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_turn_num_raises
@nick varchar(50),
@host_id int
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[ACtion] = 7
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_raises_showdown    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE PROCEDURE  sp_turn_num_raises_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[Action] = 7
AND ActionsView.[First Card Rank]> 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_raises_won_showdown    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE PROCEDURE  sp_turn_num_raises_won_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3
AND ActionsView.[Action] = 7
AND ActionsView.[First Card Rank]> 0
AND ActionsView.[Win Loss] > 0
AND Variant = @Variant
AND [date] > @Date



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_num_seen    Script Date: 11/02/2003 2:40:58 PM ******/
CREATE PROCEDURE sp_num_turns_seen
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(distinct ActionsView.[Hand id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 3

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_raise_river_call    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE  PROCEDURE  sp_turn_raise_river_call
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 3
AND SecondAction.[Round] = 4
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 7 
AND SecondAction.[Action] = 5
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_raise_river_fold    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE  PROCEDURE  sp_turn_raise_river_fold
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 3
AND SecondAction.[Round] = 4
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 7 
AND SecondAction.[Action] = 3
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_turn_raise_river_raise    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE  PROCEDURE  sp_turn_raise_river_raise
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(FirstAction.[Action id])
from ActionsView FirstAction, ActionsView SecondAction 
where

FirstAction.[player id] = @NickId
AND SecondAction.[player id] = @NickId
AND FirstAction.[Hand id] =  SecondAction.[Hand id]
AND FirstAction.[Host id] = @host_id
AND FirstAction.[Round] = 3
AND SecondAction.[Round] = 4
AND FirstAction.[Action id] < SecondAction.[Action id]
AND FirstAction.[Action] = 7 
AND SecondAction.[Action] = 7
AND FirstAction.Variant = @Variant
AND FirstAction.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_delete_hand    Script Date: 11/02/2003 2:40:58 PM ******/


CREATE    PROCEDURE sp_delete_hand
@HandReference int
 AS


declare @HandId int
select @HandId = [Hand Id] from Hands 
where [Hand reference] = @HandReference
	AND Incomplete > 0

delete from Actions
where [FK_Results Id]
	in (select [Individual Results Id] from [Individual Results]
		where [FK_Hand Id] = @HandId)

delete from [Individual Results]
where [FK_Hand Id] = @HandId

delete from Hands where [Hand Id] = @HandId







GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_preflop_num_vol_put_money_in_Pot    Script Date: 11/02/2003 2:40:58 PM ******/


CREATE   PROCEDURE sp_preflop_num_vol_put_money_in_Pot
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962',
@num_players int = 9
AS

declare @NickId int
select @NickId = [player id] from Players where nick = @nick

SELECT 
count(distinct ActionsView.[Hand id])
FROM  ActionsView
WHERE
	ActionsView.[player id] = @NickId
AND 	ActionsView.[FKH_Poker site] = @host_id
AND 	ActionsView.[round] = 1
AND 	(ActionsView.[Action] = 5
	OR ActionsView.[Action] = 6
	OR ActionsView.[Action] = 7)



GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_bets_won_showdown    Script Date: 11/02/2003 2:40:58 PM ******/


CREATE  PROCEDURE  sp_river_num_bets_won_showdown
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count([Action id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4
AND ActionsView.[Action] = 6
AND ActionsView.[First Card Rank]> 0
AND ActionsView.[Win Loss] > 0
AND ActionsView.Variant = @Variant
AND ActionsView.[date] > @Date




GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  Stored Procedure dbo.sp_river_num_seen    Script Date: 11/02/2003 2:40:58 PM ******/

CREATE  PROCEDURE sp_river_num_seen
@nick varchar(50),
@host_id int,
@Variant int = 0,
@Date datetime = '1962'
 AS


declare @NickId int
select @NickId = [player id] from Players where nick = @nick

select
count(distinct ActionsView.[Hand id])
from ActionsView 
where
ActionsView.[player id] = @NickId
AND ActionsView.[Host id] = @host_id
AND ActionsView.[Round] = 4


GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

