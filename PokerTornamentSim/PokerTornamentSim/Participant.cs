using System;

namespace PokerTornamentSim
{
	/// <summary>
	/// Summary description for Class1.
	/// </summary>
	public class Participant
	{
		public Participant()
		{
			//
			// TODO: Add constructor logic here
			//
		}

		/// <summary>
		/// Current tournament chips
		/// </summary>
		public long Chips
		{
			get
			{
				return chips;
			}
			set
			{
				chips = value;
			}
		}

		private long chips;
		private long winnings;
		private long numTornamentsEntered;

		public void bustedOut(int tornementPsition, int tornementWinnings)
		{
			winnings += tornementWinnings;
			numTornamentsEntered++;
		}

		public float EV
		{
			get
			{
				return (float)winnings/(float)numTornamentsEntered;
			}
		}

		private long startingChips;
		public long StartingChips
		{
			get
			{
				return startingChips;
			}
			set
			{
				startingChips = value;
			}
		}
 	}
}
