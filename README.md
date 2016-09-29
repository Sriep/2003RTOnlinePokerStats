# 2003RTOnlinePokerStats

End of 2003 I started working as a professional online poker player. This was before poker tracker and Holdem manager, so I wrote my own real-time online poker stats and hand history tracking program. 

This is it. 

I would not advise trying to get it working but it might give some ideas to anyone trying to start a similar project.

Supported 18 poker sites most of which are now defunct.  It mostly used hooks to access poker client messages of hand information so stats could be updated in real time. It was designed to be used across several computers, collecting hand histories.  SQLServer7 was used to hold all the database information. 

It required a lot of upkeep to support constant changes in game client software, so when the likes of poker tracker and Holdem manager started providing real-time status and HUDs I stopped development on this project. 

ICMMod is a separate program that provides ICM information for the final table at tournaments. 
