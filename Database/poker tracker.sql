if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_game_game_level]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[game] DROP CONSTRAINT FK_game_game_level
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_game_game_level1]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[game] DROP CONSTRAINT FK_game_game_level1
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_player_winnings_game_level]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[player_winnings] DROP CONSTRAINT FK_player_winnings_game_level
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_session_game_level]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[session] DROP CONSTRAINT FK_session_game_level
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_game_players_hand_rank]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[game_players] DROP CONSTRAINT FK_game_players_hand_rank
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_tourney_game_players_hand_rank]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[tourney_game_players] DROP CONSTRAINT FK_tourney_game_players_hand_rank
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_game_poker_sites]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[game] DROP CONSTRAINT FK_game_poker_sites
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_game_poker_sites1]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[game] DROP CONSTRAINT FK_game_poker_sites1
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_player_winnings_poker_sites]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[player_winnings] DROP CONSTRAINT FK_player_winnings_poker_sites
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_players_poker_sites]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[players] DROP CONSTRAINT FK_players_poker_sites
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_session_poker_sites]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[session] DROP CONSTRAINT FK_session_poker_sites
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_tourney_poker_sites]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[tourney] DROP CONSTRAINT FK_tourney_poker_sites
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_game_players]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[game] DROP CONSTRAINT FK_game_players
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_game_players_players]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[game_players] DROP CONSTRAINT FK_game_players_players
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_player_winnings_players]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[player_winnings] DROP CONSTRAINT FK_player_winnings_players
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_player_winnings_players1]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[player_winnings] DROP CONSTRAINT FK_player_winnings_players1
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_player_winnings_players2]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[player_winnings] DROP CONSTRAINT FK_player_winnings_players2
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_player_winnings_players3]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[player_winnings] DROP CONSTRAINT FK_player_winnings_players3
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_tourney_game_players]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[tourney_game] DROP CONSTRAINT FK_tourney_game_players
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_tourney_game_players_players]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[tourney_game_players] DROP CONSTRAINT FK_tourney_game_players_players
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_tourney_summary_players]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[tourney_summary] DROP CONSTRAINT FK_tourney_summary_players
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_game_players_session]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[game_players] DROP CONSTRAINT FK_game_players_session
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_player_winnings_session]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[player_winnings] DROP CONSTRAINT FK_player_winnings_session
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_tourney_game_tourney]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[tourney_game] DROP CONSTRAINT FK_tourney_game_tourney
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_tourney_summary_tourney]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[tourney_summary] DROP CONSTRAINT FK_tourney_summary_tourney
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FK_game_players_game]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
ALTER TABLE [dbo].[game_players] DROP CONSTRAINT FK_game_players_game
GO

/****** Object:  Stored Procedure dbo.sp_PlayerSummary    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_PlayerSummary]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_PlayerSummary]
GO

/****** Object:  Stored Procedure dbo.sp_BBWon_vs_PFR    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_BBWon_vs_PFR]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_BBWon_vs_PFR]
GO

/****** Object:  Stored Procedure dbo.sp_BBwon_vs_VPIF    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[sp_BBwon_vs_VPIF]') and OBJECTPROPERTY(id, N'IsProcedure') = 1)
drop procedure [dbo].[sp_BBwon_vs_VPIF]
GO

/****** Object:  View dbo.PlayerSummary    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[PlayerSummary]') and OBJECTPROPERTY(id, N'IsView') = 1)
drop view [dbo].[PlayerSummary]
GO

/****** Object:  View dbo.ViewGamePlayer    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[ViewGamePlayer]') and OBJECTPROPERTY(id, N'IsView') = 1)
drop view [dbo].[ViewGamePlayer]
GO

/****** Object:  View dbo.Sumary    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Sumary]') and OBJECTPROPERTY(id, N'IsView') = 1)
drop view [dbo].[Sumary]
GO

/****** Object:  View dbo.SessionPiers    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[SessionPiers]') and OBJECTPROPERTY(id, N'IsView') = 1)
drop view [dbo].[SessionPiers]
GO

/****** Object:  Table [dbo].[game_players]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[game_players]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[game_players]
GO

/****** Object:  Table [dbo].[game]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[game]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[game]
GO

/****** Object:  Table [dbo].[player_winnings]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[player_winnings]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[player_winnings]
GO

/****** Object:  Table [dbo].[tourney_game]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[tourney_game]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[tourney_game]
GO

/****** Object:  Table [dbo].[tourney_game_players]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[tourney_game_players]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[tourney_game_players]
GO

/****** Object:  Table [dbo].[tourney_summary]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[tourney_summary]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[tourney_summary]
GO

/****** Object:  Table [dbo].[players]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[players]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[players]
GO

/****** Object:  Table [dbo].[session]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[session]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[session]
GO

/****** Object:  Table [dbo].[tourney]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[tourney]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[tourney]
GO

/****** Object:  Table [dbo].[blind_structure]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[blind_structure]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[blind_structure]
GO

/****** Object:  Table [dbo].[dst]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[dst]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[dst]
GO

/****** Object:  Table [dbo].[exrates]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[exrates]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[exrates]
GO

/****** Object:  Table [dbo].[game_level]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[game_level]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[game_level]
GO

/****** Object:  Table [dbo].[hand_rank]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[hand_rank]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[hand_rank]
GO

/****** Object:  Table [dbo].[poker_sites]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[poker_sites]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[poker_sites]
GO

/****** Object:  Table [dbo].[prefs]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[prefs]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[prefs]
GO

/****** Object:  Table [dbo].[version_info]    Script Date: 10/27/2004 6:53:44 PM ******/
if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[version_info]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[version_info]
GO

/****** Object:  Table [dbo].[blind_structure]    Script Date: 10/27/2004 6:53:52 PM ******/
CREATE TABLE [dbo].[blind_structure] (
	[blind_structure_id] [int] NOT NULL ,
	[blind_structure_desc] [nvarchar] (20) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[big_bet] [int] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[dst]    Script Date: 10/27/2004 6:53:55 PM ******/
CREATE TABLE [dbo].[dst] (
	[date_from] [smalldatetime] NOT NULL ,
	[date_to] [smalldatetime] NULL ,
	[dst_value] [int] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[exrates]    Script Date: 10/27/2004 6:53:55 PM ******/
CREATE TABLE [dbo].[exrates] (
	[exdate] [smalldatetime] NULL ,
	[usd] [float] NULL ,
	[gbp] [float] NULL ,
	[euro] [float] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[game_level]    Script Date: 10/27/2004 6:53:55 PM ******/
CREATE TABLE [dbo].[game_level] (
	[game_level_id] [int] NOT NULL ,
	[game_level_desc] [nvarchar] (20) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL ,
	[game_level_big_bet] [float] NOT NULL ,
	[pl_nl] [int] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[hand_rank]    Script Date: 10/27/2004 6:53:56 PM ******/
CREATE TABLE [dbo].[hand_rank] (
	[hand_rank_id] [int] NOT NULL ,
	[hand_rank_desc] [nvarchar] (30) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[poker_sites]    Script Date: 10/27/2004 6:53:56 PM ******/
CREATE TABLE [dbo].[poker_sites] (
	[site_id] [int] NOT NULL ,
	[site_abbrev] [nvarchar] (3) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[site_name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[prefs]    Script Date: 10/27/2004 6:53:56 PM ******/
CREATE TABLE [dbo].[prefs] (
	[pref_key] [nvarchar] (20) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL ,
	[pref_value] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[long_pref] [ntext] COLLATE SQL_Latin1_General_CP1_CI_AS NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

/****** Object:  Table [dbo].[version_info]    Script Date: 10/27/2004 6:53:57 PM ******/
CREATE TABLE [dbo].[version_info] (
	[db_version] [nvarchar] (20) COLLATE SQL_Latin1_General_CP1_CI_AS NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[players]    Script Date: 10/27/2004 6:53:57 PM ******/
CREATE TABLE [dbo].[players] (
	[player_id] [int] NOT NULL ,
	[screen_name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL ,
	[location] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[general_description] [ntext] COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[treeview_icon] [int] NULL ,
	[site_id] [int] NULL ,
	[alias_id] [int] NULL ,
	[main_site_id] [int] NULL ,
	[hide_ind] [int] NULL ,
	[ring_player] [int] NULL ,
	[tourney_player] [int] NULL ,
	[tourney_hide_ind] [int] NULL ,
	[last_icon] [float] NULL ,
	[last_auto_rated] [smalldatetime] NULL ,
	[last_batch_rated] [smalldatetime] NULL ,
	[icon_before_batch_rate] [float] NULL ,
	[no_auto_rate] [float] NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

/****** Object:  Table [dbo].[session]    Script Date: 10/27/2004 6:53:58 PM ******/
CREATE TABLE [dbo].[session] (
	[session_id] [int] NOT NULL ,
	[player_id] [int] NULL ,
	[session_start] [smalldatetime] NOT NULL ,
	[session_end] [smalldatetime] NOT NULL ,
	[table_name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL ,
	[seat_number] [int] NULL ,
	[session_notes] [ntext] COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[game_level_id] [int] NULL ,
	[amount_won] [float] NULL ,
	[total_hands] [int] NULL ,
	[site_id] [int] NULL ,
	[vol_saw_flop] [int] NULL ,
	[pre_flop_raise] [int] NULL ,
	[att_steal] [int] NULL ,
	[chance_to_steal] [int] NULL ,
	[won_hand] [int] NULL ,
	[went_to_sd] [int] NULL ,
	[won_at_sd] [int] NULL ,
	[real_player_id] [int] NULL ,
	[tot_players] [int] NULL ,
	[tot_saw_flop] [int] NULL ,
	[tot_pot] [money] NULL ,
	[cur_ind] [float] NULL ,
	[exrate] [float] NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

/****** Object:  Table [dbo].[tourney]    Script Date: 10/27/2004 6:53:58 PM ******/
CREATE TABLE [dbo].[tourney] (
	[tourney_id] [int] NOT NULL ,
	[site_id] [int] NULL ,
	[tourney_number] [int] NULL ,
	[tourney_start] [smalldatetime] NULL ,
	[tourney_end] [smalldatetime] NULL ,
	[buy_in] [money] NULL ,
	[fee] [money] NULL ,
	[tourney_type] [int] NULL ,
	[table_type] [int] NULL ,
	[start_game_number] [int] NULL ,
	[end_game_number] [int] NULL ,
	[summary_text] [ntext] COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[target_tourney_number] [int] NULL ,
	[number_of_players] [int] NULL ,
	[tourney_notes] [ntext] COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[summary_loaded] [int] NULL ,
	[pp_table_name] [nvarchar] (25) COLLATE SQL_Latin1_General_CP1_CI_AS NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

/****** Object:  Table [dbo].[game]    Script Date: 10/27/2004 6:53:58 PM ******/
CREATE TABLE [dbo].[game] (
	[game_id] [int] NOT NULL ,
	[game_number] [int] NOT NULL ,
	[site_id] [int] NULL ,
	[date_played] [smalldatetime] NOT NULL ,
	[game_level_id] [int] NULL ,
	[flop_1] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[flop_2] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[flop_3] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[turn] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[river] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[pot] [money] NULL ,
	[rake] [money] NULL ,
	[player_id] [int] NULL ,
	[import_date] [smalldatetime] NULL ,
	[game_notes] [ntext] COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[table_name] [nvarchar] (25) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[winning_hand] [nvarchar] (255) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[real_player_id] [int] NULL ,
	[players_saw_flop] [int] NULL ,
	[number_of_players] [int] NULL ,
	[ub_game_number] [nvarchar] (30) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[ub_kill_game] [int] NULL ,
	[cur_ind] [float] NULL ,
	[exrate] [float] NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

/****** Object:  Table [dbo].[player_winnings]    Script Date: 10/27/2004 6:53:58 PM ******/
CREATE TABLE [dbo].[player_winnings] (
	[date_played] [smalldatetime] NULL ,
	[game_level_id] [int] NULL ,
	[site_id] [int] NULL ,
	[player_id] [int] NULL ,
	[session_id] [int] NULL ,
	[opponent_id] [int] NULL ,
	[won_from] [money] NULL ,
	[times_beat] [int] NULL ,
	[real_player_id] [int] NULL ,
	[real_opp_id] [int] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[tourney_game]    Script Date: 10/27/2004 6:53:59 PM ******/
CREATE TABLE [dbo].[tourney_game] (
	[tourney_id] [int] NULL ,
	[game_id] [int] NULL ,
	[game_number] [int] NULL ,
	[date_played] [smalldatetime] NULL ,
	[blind_structure_id] [int] NULL ,
	[game_level] [nvarchar] (5) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[pp_game_number] [int] NULL ,
	[flop_1] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[flop_2] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[flop_3] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[turn] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[river] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[pot] [money] NULL ,
	[player_id] [int] NULL ,
	[import_date] [smalldatetime] NULL ,
	[game_notes] [ntext] COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[table_name] [nvarchar] (100) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[winning_hand] [nvarchar] (255) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[real_player_id] [int] NULL ,
	[players_saw_flop] [int] NULL ,
	[number_of_players] [int] NULL ,
	[heads_up] [int] NULL ,
	[ub_game_number] [nvarchar] (30) COLLATE SQL_Latin1_General_CP1_CI_AS NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

/****** Object:  Table [dbo].[tourney_game_players]    Script Date: 10/27/2004 6:53:59 PM ******/
CREATE TABLE [dbo].[tourney_game_players] (
	[tourney_id] [int] NULL ,
	[game_id] [int] NULL ,
	[player_id] [int] NULL ,
	[seat_number] [int] NULL ,
	[button] [int] NULL ,
	[hole_card_1] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[hole_card_2] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[suited] [nvarchar] (1) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[pre_flop_bet] [money] NULL ,
	[flop_bet] [money] NULL ,
	[turn_bet] [money] NULL ,
	[river_bet] [money] NULL ,
	[total_bet] [money] NULL ,
	[total_won] [money] NULL ,
	[when_folded] [nvarchar] (15) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[final_hand] [nvarchar] (255) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[hand_rank_id] [int] NULL ,
	[all_in] [int] NULL ,
	[forced_all_in] [int] NULL ,
	[hole_cards] [nvarchar] (3) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[card_order1] [int] NULL ,
	[card_order2] [int] NULL ,
	[card_order3] [int] NULL ,
	[connector_hand] [int] NULL ,
	[pair_hand] [int] NULL ,
	[won_hand] [int] NULL ,
	[off_the_button] [int] NULL ,
	[number_of_players] [int] NULL ,
	[big_blind_n] [int] NULL ,
	[small_blind_n] [int] NULL ,
	[pre_flop_raise_n] [int] NULL ,
	[flop_raise_n] [int] NULL ,
	[flop_ck_raise_n] [int] NULL ,
	[turn_bet_raise_n] [int] NULL ,
	[turn_bet_ck_raise_n] [int] NULL ,
	[river_bet_raise_n] [int] NULL ,
	[river_bet_ck_raise_n] [int] NULL ,
	[went_to_showdown_n] [int] NULL ,
	[saw_flop_n] [int] NULL ,
	[saw_flop_blind_n] [int] NULL ,
	[attempted_steal] [int] NULL ,
	[chance_to_steal] [int] NULL ,
	[steal_attempted] [int] NULL ,
	[folded_to_steal_attempt] [int] NULL ,
	[raised_first_pf] [int] NULL ,
	[vol_put_money_in_pot] [int] NULL ,
	[limp_with_prev_callers] [int] NULL ,
	[ppossible_actions] [int] NULL ,
	[pfold] [int] NULL ,
	[pcheck] [int] NULL ,
	[pbet] [int] NULL ,
	[praise] [int] NULL ,
	[pcall] [int] NULL ,
	[limp_call_reraise_pf] [int] NULL ,
	[pfr_check] [int] NULL ,
	[pfr_call] [int] NULL ,
	[pfr_fold] [int] NULL ,
	[pfr_bet] [int] NULL ,
	[pfr_raise] [int] NULL ,
	[folded_to_river_bet] [int] NULL ,
	[fpossible_actions] [int] NULL ,
	[ffold] [int] NULL ,
	[fcheck] [int] NULL ,
	[fbet] [int] NULL ,
	[fraise] [int] NULL ,
	[fcall] [int] NULL ,
	[tpossible_actions] [int] NULL ,
	[tfold] [int] NULL ,
	[tcheck] [int] NULL ,
	[tbet] [int] NULL ,
	[traise] [int] NULL ,
	[tcall] [int] NULL ,
	[rpossible_actions] [int] NULL ,
	[rfold] [int] NULL ,
	[rcheck] [int] NULL ,
	[rbet] [int] NULL ,
	[rraise] [int] NULL ,
	[rcall] [int] NULL ,
	[real_player_id] [int] NULL ,
	[cold_call_pf] [int] NULL ,
	[steal_hu_chance] [int] NULL ,
	[steal_hu_fold] [int] NULL ,
	[chip_count] [money] NULL ,
	[blind_amt] [money] NULL ,
	[ante_amt] [money] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[tourney_summary]    Script Date: 10/27/2004 6:54:00 PM ******/
CREATE TABLE [dbo].[tourney_summary] (
	[tourney_id] [int] NULL ,
	[place_of_finish] [int] NULL ,
	[player_id] [int] NULL ,
	[amt_won] [money] NULL ,
	[real_player_id] [int] NULL ,
	[sat_seat_won] [int] NULL ,
	[actual_buy_in] [money] NULL ,
	[actual_fee] [money] NULL ,
	[total_rebuys] [int] NULL ,
	[rebuy_amt] [money] NULL ,
	[total_addons] [int] NULL ,
	[addon_amt] [money] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[game_players]    Script Date: 10/27/2004 6:54:00 PM ******/
CREATE TABLE [dbo].[game_players] (
	[game_id] [int] NULL ,
	[player_id] [int] NULL ,
	[seat_number] [int] NOT NULL ,
	[button] [int] NOT NULL ,
	[hole_card_1] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[hole_card_2] [nvarchar] (2) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[suited] [nvarchar] (1) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[pre_flop_bet] [money] NULL ,
	[flop_bet] [money] NULL ,
	[turn_bet] [money] NULL ,
	[river_bet] [money] NULL ,
	[total_bet] [money] NULL ,
	[total_won] [money] NULL ,
	[when_folded] [nvarchar] (15) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[played_hand] [nvarchar] (1) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL ,
	[player_notes] [nvarchar] (255) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[final_hand] [nvarchar] (255) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[hand_rank_id] [int] NULL ,
	[all_in] [int] NULL ,
	[forced_all_in] [int] NULL ,
	[hole_cards] [nvarchar] (3) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[card_order1] [int] NULL ,
	[card_order2] [int] NULL ,
	[card_order3] [int] NULL ,
	[connector_hand] [int] NULL ,
	[pair_hand] [int] NULL ,
	[won_hand] [int] NULL ,
	[session_id] [int] NULL ,
	[off_the_button] [int] NULL ,
	[number_of_players] [int] NULL ,
	[big_blind_n] [int] NULL ,
	[small_blind_n] [int] NULL ,
	[pre_flop_raise_n] [int] NULL ,
	[flop_raise_n] [int] NULL ,
	[flop_ck_raise_n] [int] NULL ,
	[turn_bet_raise_n] [int] NULL ,
	[turn_bet_ck_raise_n] [int] NULL ,
	[river_bet_raise_n] [int] NULL ,
	[river_bet_ck_raise_n] [int] NULL ,
	[went_to_showdown_n] [int] NULL ,
	[saw_flop_n] [int] NULL ,
	[saw_flop_blind_n] [int] NULL ,
	[attempted_steal] [int] NULL ,
	[chance_to_steal] [int] NULL ,
	[steal_attempted] [int] NULL ,
	[folded_to_steal_attempt] [int] NULL ,
	[raised_first_pf] [int] NULL ,
	[vol_put_money_in_pot] [int] NULL ,
	[limp_with_prev_callers] [int] NULL ,
	[ppossible_actions] [int] NULL ,
	[pfold] [int] NULL ,
	[pcheck] [int] NULL ,
	[praise] [int] NULL ,
	[pcall] [int] NULL ,
	[limp_call_reraise_pf] [int] NULL ,
	[pfr_check] [int] NULL ,
	[pfr_call] [int] NULL ,
	[pfr_fold] [int] NULL ,
	[pfr_bet] [int] NULL ,
	[pfr_raise] [int] NULL ,
	[folded_to_river_bet] [int] NULL ,
	[fpossible_actions] [int] NULL ,
	[ffold] [int] NULL ,
	[fcheck] [int] NULL ,
	[fbet] [int] NULL ,
	[fraise] [int] NULL ,
	[fcall] [int] NULL ,
	[tpossible_actions] [int] NULL ,
	[tfold] [int] NULL ,
	[tcheck] [int] NULL ,
	[tbet] [int] NULL ,
	[traise] [int] NULL ,
	[tcall] [int] NULL ,
	[rpossible_actions] [int] NULL ,
	[rfold] [int] NULL ,
	[rcheck] [int] NULL ,
	[rbet] [int] NULL ,
	[rraise] [int] NULL ,
	[rcall] [int] NULL ,
	[blind_amt] [money] NULL ,
	[real_player_id] [int] NULL ,
	[cold_call_pf] [int] NULL ,
	[steal_hu_chance] [int] NULL ,
	[steal_hu_fold] [int] NULL ,
	[chip_count] [money] NULL ,
	[ub_kill_blind] [int] NULL 
) ON [PRIMARY]
GO

ALTER TABLE [dbo].[blind_structure] WITH NOCHECK ADD 
	CONSTRAINT [PK_blind_structure] PRIMARY KEY  CLUSTERED 
	(
		[blind_structure_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[game_level] WITH NOCHECK ADD 
	CONSTRAINT [PK_game_level] PRIMARY KEY  CLUSTERED 
	(
		[game_level_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[hand_rank] WITH NOCHECK ADD 
	CONSTRAINT [PK_hand_rank] PRIMARY KEY  CLUSTERED 
	(
		[hand_rank_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[poker_sites] WITH NOCHECK ADD 
	CONSTRAINT [PK_poker_sites] PRIMARY KEY  CLUSTERED 
	(
		[site_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[prefs] WITH NOCHECK ADD 
	CONSTRAINT [PK_prefs] PRIMARY KEY  CLUSTERED 
	(
		[pref_key]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[players] WITH NOCHECK ADD 
	CONSTRAINT [PK_players] PRIMARY KEY  CLUSTERED 
	(
		[player_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[session] WITH NOCHECK ADD 
	CONSTRAINT [PK_session] PRIMARY KEY  CLUSTERED 
	(
		[session_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[tourney] WITH NOCHECK ADD 
	CONSTRAINT [PK_tourney] PRIMARY KEY  CLUSTERED 
	(
		[tourney_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[game] WITH NOCHECK ADD 
	CONSTRAINT [PK_game] PRIMARY KEY  CLUSTERED 
	(
		[game_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[blind_structure] ADD 
	CONSTRAINT [IX_blind_structure] UNIQUE  NONCLUSTERED 
	(
		[blind_structure_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[dst] ADD 
	CONSTRAINT [IX_dst] UNIQUE  NONCLUSTERED 
	(
		[date_from]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[game] ADD 
	CONSTRAINT [IX_game] UNIQUE  NONCLUSTERED 
	(
		[game_id]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[players] ADD 
	CONSTRAINT [FK_players_poker_sites] FOREIGN KEY 
	(
		[site_id]
	) REFERENCES [dbo].[poker_sites] (
		[site_id]
	)
GO

ALTER TABLE [dbo].[session] ADD 
	CONSTRAINT [FK_session_game_level] FOREIGN KEY 
	(
		[game_level_id]
	) REFERENCES [dbo].[game_level] (
		[game_level_id]
	),
	CONSTRAINT [FK_session_poker_sites] FOREIGN KEY 
	(
		[site_id]
	) REFERENCES [dbo].[poker_sites] (
		[site_id]
	)
GO

ALTER TABLE [dbo].[tourney] ADD 
	CONSTRAINT [FK_tourney_poker_sites] FOREIGN KEY 
	(
		[site_id]
	) REFERENCES [dbo].[poker_sites] (
		[site_id]
	)
GO

ALTER TABLE [dbo].[game] ADD 
	CONSTRAINT [FK_game_game_level] FOREIGN KEY 
	(
		[game_level_id]
	) REFERENCES [dbo].[game_level] (
		[game_level_id]
	),
	CONSTRAINT [FK_game_game_level1] FOREIGN KEY 
	(
		[game_level_id]
	) REFERENCES [dbo].[game_level] (
		[game_level_id]
	),
	CONSTRAINT [FK_game_players] FOREIGN KEY 
	(
		[player_id]
	) REFERENCES [dbo].[players] (
		[player_id]
	),
	CONSTRAINT [FK_game_poker_sites] FOREIGN KEY 
	(
		[site_id]
	) REFERENCES [dbo].[poker_sites] (
		[site_id]
	),
	CONSTRAINT [FK_game_poker_sites1] FOREIGN KEY 
	(
		[site_id]
	) REFERENCES [dbo].[poker_sites] (
		[site_id]
	)
GO

ALTER TABLE [dbo].[player_winnings] ADD 
	CONSTRAINT [FK_player_winnings_game_level] FOREIGN KEY 
	(
		[game_level_id]
	) REFERENCES [dbo].[game_level] (
		[game_level_id]
	),
	CONSTRAINT [FK_player_winnings_players] FOREIGN KEY 
	(
		[player_id]
	) REFERENCES [dbo].[players] (
		[player_id]
	),
	CONSTRAINT [FK_player_winnings_players1] FOREIGN KEY 
	(
		[opponent_id]
	) REFERENCES [dbo].[players] (
		[player_id]
	),
	CONSTRAINT [FK_player_winnings_players2] FOREIGN KEY 
	(
		[real_player_id]
	) REFERENCES [dbo].[players] (
		[player_id]
	),
	CONSTRAINT [FK_player_winnings_players3] FOREIGN KEY 
	(
		[real_opp_id]
	) REFERENCES [dbo].[players] (
		[player_id]
	),
	CONSTRAINT [FK_player_winnings_poker_sites] FOREIGN KEY 
	(
		[site_id]
	) REFERENCES [dbo].[poker_sites] (
		[site_id]
	),
	CONSTRAINT [FK_player_winnings_session] FOREIGN KEY 
	(
		[session_id]
	) REFERENCES [dbo].[session] (
		[session_id]
	)
GO

ALTER TABLE [dbo].[tourney_game] ADD 
	CONSTRAINT [FK_tourney_game_players] FOREIGN KEY 
	(
		[player_id]
	) REFERENCES [dbo].[players] (
		[player_id]
	),
	CONSTRAINT [FK_tourney_game_tourney] FOREIGN KEY 
	(
		[tourney_id]
	) REFERENCES [dbo].[tourney] (
		[tourney_id]
	)
GO

ALTER TABLE [dbo].[tourney_game_players] ADD 
	CONSTRAINT [FK_tourney_game_players_hand_rank] FOREIGN KEY 
	(
		[hand_rank_id]
	) REFERENCES [dbo].[hand_rank] (
		[hand_rank_id]
	),
	CONSTRAINT [FK_tourney_game_players_players] FOREIGN KEY 
	(
		[player_id]
	) REFERENCES [dbo].[players] (
		[player_id]
	)
GO

ALTER TABLE [dbo].[tourney_summary] ADD 
	CONSTRAINT [FK_tourney_summary_players] FOREIGN KEY 
	(
		[player_id]
	) REFERENCES [dbo].[players] (
		[player_id]
	),
	CONSTRAINT [FK_tourney_summary_tourney] FOREIGN KEY 
	(
		[tourney_id]
	) REFERENCES [dbo].[tourney] (
		[tourney_id]
	)
GO

ALTER TABLE [dbo].[game_players] ADD 
	CONSTRAINT [FK_game_players_game] FOREIGN KEY 
	(
		[game_id]
	) REFERENCES [dbo].[game] (
		[game_id]
	),
	CONSTRAINT [FK_game_players_hand_rank] FOREIGN KEY 
	(
		[hand_rank_id]
	) REFERENCES [dbo].[hand_rank] (
		[hand_rank_id]
	),
	CONSTRAINT [FK_game_players_players] FOREIGN KEY 
	(
		[player_id]
	) REFERENCES [dbo].[players] (
		[player_id]
	),
	CONSTRAINT [FK_game_players_session] FOREIGN KEY 
	(
		[session_id]
	) REFERENCES [dbo].[session] (
		[session_id]
	)
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  View dbo.SessionPiers    Script Date: 10/27/2004 6:54:01 PM ******/
CREATE VIEW dbo.SessionPiers
AS
SELECT     dbo.players.screen_name, dbo.[session].session_id, dbo.[session].amount_won, dbo.[session].pre_flop_raise, dbo.game_level.game_level_big_bet, 
                      dbo.[session].pre_flop_raise AS TotalPFR, dbo.[session].player_id, dbo.[session].tot_saw_flop, dbo.[session].total_hands, 
                      dbo.[session].amount_won / dbo.game_level.game_level_big_bet AS BBwon, dbo.[session].vol_saw_flop, dbo.[session].tot_players, 
                      dbo.[session].tot_players / dbo.[session].total_hands AS AvPlayers
FROM         dbo.[session] INNER JOIN
                      dbo.game_level ON dbo.[session].game_level_id = dbo.game_level.game_level_id INNER JOIN
                      dbo.players ON dbo.[session].player_id = dbo.players.player_id

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  View dbo.Sumary    Script Date: 10/27/2004 6:54:01 PM ******/
CREATE VIEW dbo.Sumary
AS
SELECT     screen_name, SUM(amount_won) AS ScreenName, SUM(total_hands) AS totalhands, SUM(vol_saw_flop) AS TotalVPIF, 100 * SUM(vol_saw_flop) 
                      / SUM(total_hands) AS averageVPIF, SUM(TotalPFR) AS TotalPFR, SUM(TotalPFR) / SUM(total_hands) AS averagePFR, SUM(BBwon) 
                      AS BigBetsWon
FROM         dbo.SessionPiers
GROUP BY screen_name

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  View dbo.PlayerSummary    Script Date: 10/27/2004 6:54:01 PM ******/
CREATE VIEW dbo.PlayerSummary
AS
SELECT     dbo.game_players.player_id AS playerId, COUNT(*) AS HandCount, SUM(dbo.game_players.total_won) AS total_won, 
                      SUM(dbo.game_players.total_won / dbo.game_level.game_level_big_bet) AS bigblinds_won, SUM(dbo.game_players.pre_flop_raise_n) 
                      AS pre_flop_raise_n, SUM(dbo.game_players.flop_raise_n) AS flop_raise_n, SUM(dbo.game_players.flop_ck_raise_n) AS flop_ck_raise_n, 
                      SUM(dbo.game_players.turn_bet_raise_n) AS turn_bet_raise_n, SUM(dbo.game_players.turn_bet_ck_raise_n) AS turn_bet_ck_raise_n, 
                      SUM(dbo.game_players.river_bet_raise_n) AS river_bet_raise_n, SUM(dbo.game_players.river_bet_ck_raise_n) AS river_bet_ck_raise_n, 
                      SUM(dbo.game_players.raised_first_pf) AS raised_first_pf, SUM(dbo.game_players.vol_put_money_in_pot) AS vol_put_money_in_pot, 
                      SUM(dbo.game_players.limp_with_prev_callers) AS limp_with_prev_callers, SUM(dbo.game_players.ppossible_actions) AS ppossible_actions, 
                      SUM(dbo.game_players.pfold) AS pfold, SUM(dbo.game_players.pcheck) AS pcheck, SUM(dbo.game_players.praise) AS praise, 
                      SUM(dbo.game_players.pcall) AS pcall, SUM(dbo.game_players.pfr_check) AS pfr_check, SUM(dbo.game_players.pfr_call) AS pfr_call, 
                      SUM(dbo.game_players.pfr_raise) AS pfr_raise, SUM(dbo.game_players.pfr_bet) AS pfr_bet, SUM(dbo.game_players.pfr_fold) AS pfr_fold, 
                      SUM(dbo.game_players.fpossible_actions) AS fpossible_actions, SUM(dbo.game_players.ffold) AS ffold, SUM(dbo.game_players.fcheck) AS fcheck, 
                      SUM(dbo.game_players.fbet) AS fbet, SUM(dbo.game_players.fraise) AS fraise, SUM(dbo.game_players.fcall) AS fcall, 
                      SUM(dbo.game_players.tpossible_actions) AS tpossible_actions, SUM(dbo.game_players.tfold) AS tfold, SUM(dbo.game_players.tcheck) AS tcheck, 
                      SUM(dbo.game_players.tbet) AS tbet, SUM(dbo.game_players.traise) AS traise, SUM(dbo.game_players.tcall) AS tcall, 
                      SUM(dbo.game_players.rpossible_actions) AS rpossible_actions, SUM(dbo.game_players.rfold) AS rfold, SUM(dbo.game_players.rcheck) AS rcheck, 
                      SUM(dbo.game_players.rbet) AS rbet, SUM(dbo.game_players.rraise) AS rraise, SUM(dbo.game_players.rcall) AS rcall, 
                      SUM(dbo.game_players.cold_call_pf) AS ascold_call_pf
FROM         dbo.game_players INNER JOIN
                      dbo.game ON dbo.game_players.game_id = dbo.game.game_id INNER JOIN
                      dbo.game_level ON dbo.game.game_level_id = dbo.game_level.game_level_id
WHERE     (dbo.game_players.number_of_players = 9)
GROUP BY dbo.game_players.player_id

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS ON 
GO

/****** Object:  View dbo.ViewGamePlayer    Script Date: 10/27/2004 6:54:01 PM ******/
CREATE VIEW dbo.ViewGamePlayer
AS
SELECT     player_id, total_won, off_the_button, number_of_players, big_blind_n, small_blind_n, pre_flop_raise_n, flop_raise_n, flop_ck_raise_n, 
                      turn_bet_raise_n, turn_bet_ck_raise_n, river_bet_raise_n, river_bet_ck_raise_n, raised_first_pf, limp_with_prev_callers, pfold, pcheck, praise, pcall, 
                      pfr_check, pfr_call, pfr_raise, pfr_bet, pfr_fold, fpossible_actions, ffold, fcheck, fbet, fraise, fcall, tpossible_actions, tfold, tcheck, tbet, traise, tcall, 
                      rpossible_actions, rfold, rcheck, rbet, rraise, rcall, blind_amt, cold_call_pf, ppossible_actions, vol_put_money_in_pot
FROM         dbo.game_players

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_BBWon_vs_PFR    Script Date: 10/27/2004 6:54:01 PM ******/
CREATE PROCEDURE sp_BBWon_vs_PFR  AS
select  averagePFR as averagePFR, 
SUM(BigBetsWon)/SUM(totalhands) as BBWonPerHand, 
SUM(bigbetswon) as totalhands, 
Sum(totalhands)
from sumary
group by averagePFR
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_BBwon_vs_VPIF    Script Date: 10/27/2004 6:54:01 PM ******/

CREATE  PROCEDURE sp_BBwon_vs_VPIF 
@AvPlayers int = 0  AS
select averageVPIF as VPIF, 
SUM(BigBetsWon)/SUM(totalhands) as BBWonPerHand, 
Sum(totalhands) as hands
from sumary
where AvPlayers = @AvPlayers
group by averageVPIF
order by VPIF

GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

SET QUOTED_IDENTIFIER ON 
GO
SET ANSI_NULLS OFF 
GO

/****** Object:  Stored Procedure dbo.sp_PlayerSummary    Script Date: 10/27/2004 6:54:01 PM ******/
CREATE PROCEDURE sp_PlayerSummary @playersInHand int AS
SELECT     dbo.game_players.player_id AS playerId, COUNT(*) AS HandCount, SUM(dbo.game_players.total_won) AS total_won, 
                      SUM(dbo.game_players.total_won / dbo.game_level.game_level_big_bet) AS bigblinds_won, SUM(dbo.game_players.pre_flop_raise_n) 
                      AS pre_flop_raise_n, SUM(dbo.game_players.flop_raise_n) AS flop_raise_n, SUM(dbo.game_players.flop_ck_raise_n) AS flop_ck_raise_n, 
                      SUM(dbo.game_players.turn_bet_raise_n) AS turn_bet_raise_n, SUM(dbo.game_players.turn_bet_ck_raise_n) AS turn_bet_ck_raise_n, 
                      SUM(dbo.game_players.river_bet_raise_n) AS river_bet_raise_n, SUM(dbo.game_players.river_bet_ck_raise_n) AS river_bet_ck_raise_n, 
                      SUM(dbo.game_players.raised_first_pf) AS raised_first_pf, SUM(dbo.game_players.vol_put_money_in_pot) AS vol_put_money_in_pot, 
                      SUM(dbo.game_players.limp_with_prev_callers) AS limp_with_prev_callers, SUM(dbo.game_players.ppossible_actions) AS ppossible_actions, 
                      SUM(dbo.game_players.pfold) AS pfold, SUM(dbo.game_players.pcheck) AS pcheck, SUM(dbo.game_players.praise) AS praise, 
                      SUM(dbo.game_players.pcall) AS pcall, SUM(dbo.game_players.pfr_check) AS pfr_check, SUM(dbo.game_players.pfr_call) AS pfr_call, 
                      SUM(dbo.game_players.pfr_raise) AS pfr_raise, SUM(dbo.game_players.pfr_bet) AS pfr_bet, SUM(dbo.game_players.pfr_fold) AS pfr_fold, 
                      SUM(dbo.game_players.fpossible_actions) AS fpossible_actions, SUM(dbo.game_players.ffold) AS ffold, SUM(dbo.game_players.fcheck) AS fcheck, 
                      SUM(dbo.game_players.fbet) AS fbet, SUM(dbo.game_players.fraise) AS fraise, SUM(dbo.game_players.fcall) AS fcall, 
                      SUM(dbo.game_players.tpossible_actions) AS tpossible_actions, SUM(dbo.game_players.tfold) AS tfold, SUM(dbo.game_players.tcheck) AS tcheck, 
                      SUM(dbo.game_players.tbet) AS tbet, SUM(dbo.game_players.traise) AS traise, SUM(dbo.game_players.tcall) AS tcall, 
                      SUM(dbo.game_players.rpossible_actions) AS rpossible_actions, SUM(dbo.game_players.rfold) AS rfold, SUM(dbo.game_players.rcheck) AS rcheck, 
                      SUM(dbo.game_players.rbet) AS rbet, SUM(dbo.game_players.rraise) AS rraise, SUM(dbo.game_players.rcall) AS rcall, 
                      SUM(dbo.game_players.cold_call_pf) AS ascold_call_pf
FROM         dbo.game_players INNER JOIN
                      dbo.game ON dbo.game_players.game_id = dbo.game.game_id INNER JOIN
                      dbo.game_level ON dbo.game.game_level_id = dbo.game_level.game_level_id
WHERE     (dbo.game_players.number_of_players = @playersInHand)
GROUP BY dbo.game_players.player_id
GO

SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

