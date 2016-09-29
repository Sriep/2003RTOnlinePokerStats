using System;
using System.Collections;
using System.IO;
using System.Windows.Forms;

namespace PokerTornamentSim
{
	/// <summary>
	/// Summary description for TornamentSim.
	/// </summary>
	public class TornamentSim
	{
		public TornamentSim()
		{
			//
			// TODO: Add constructor logic here
			//
		}


		public void SimulateTornament(ArrayList participants)
		{
			playersLeft = (System.Collections.ArrayList) participants.Clone();
			setupTornament(playersLeft);
			while (playersLeft.Count > 1)
			{
				playHand();
				if (handsCurrentLevel < playersLeft.Count)
				{
					handsCurrentLevel++;
				}
				else
				{
					blindLevel *= 2;
					handsCurrentLevel = 0;
				}
			}
			if (1 == playersLeft.Count)
			{
				((Participant)playersLeft[0]).bustedOut(1, (int)prizeStructure[0]);
			}
		}
		private void setupSimulation(ArrayList participants, int averageStack)
		{
			if (participants.Count < 9)
				throw(new SystemException("Not enough players"));

			for (int index = 0 ; index < prizeStructure.Length ; index++)
			{
				prizeStructure[index] = (prizeStructure[index]*participants.Count*startingChips)/10000;
			}
			distributeStatChips(participants, averageStack);
		}

		private void distributeStatChips(ArrayList participants, int averageStack)
		{
			foreach (Participant player in participants)
			{
				player.StartingChips = startingChips;
			}
			
			int numTestStaks = participants.Count/2 - 1;
			for (int index  = 0 ; index < numTestStaks ; index++ )
			{
				long change = (startingChips*(index+1))/(numTestStaks+1);
				((Participant)participants[numTestStaks - index - 1]).StartingChips -= change;
				((Participant)participants[numTestStaks + index + 1]).StartingChips += change;
			}  
			/*
			int numTestStaks = participants.Count/3 - 1;
			for (int index  = 0 ; index < numTestStaks ; index++ )
			{
				long change = (startingChips*(index+1))/(numTestStaks+1);
				((Participant)participants[numTestStaks - index - 1]).StartingChips -= change;
				((Participant)participants[numTestStaks + index + 1]).StartingChips += change;
				((Participant)participants[numTestStaks + 2*index + 1]).StartingChips += 2*change;
			}  */
		}

		public void DoMultipleTournamentSims(int numParticipants, int numSimulations, int averageStack, ProgressBar progressBar)
		{
			startingChips = averageStack;
			ArrayList participants = new ArrayList(numParticipants);
			for ( int index = 0 ; index < numParticipants ; index++ )
			{
				participants.Add(new Participant());
			}
			setupSimulation(participants, averageStack);
			progressBar.Minimum = 0;
			progressBar.Maximum = numSimulations;
			for (int sim = 0 ; sim < numSimulations ; sim++ )
			{
				SimulateTornament(participants);
				progressBar.Value = sim;
			}
			displayResults(participants, numSimulations);
			progressBar.Value = 0;
		}

		private void playHand()
		{	
			/*
			Participant winner = (Participant)playersLeft[random.Next() % playersLeft.Count];
			Participant looser = (Participant)playersLeft[random.Next() % playersLeft.Count];
			if (looser.Chips > 7*blindLevel && winner.Chips > 7*blindLevel)
			{
				winner.Chips += 7*blindLevel;
				looser.Chips -= 7*blindLevel;
				if (looser.Chips < 0)
					throw(new SystemException("negative chips"));
			}
			else if (looser.Chips > winner.Chips)
			{
				looser.Chips -= winner.Chips;
				winner.Chips += winner.Chips;
				if (looser.Chips < 0)
					throw(new SystemException("negative chips"));
			}
			else
			{
				winner.Chips += looser.Chips;
				looser.Chips = 0;
				if (looser.Chips < 0)
					throw(new SystemException("negative chips"));
				knockedOut(looser);
			}  */
			Participant winner = (Participant)playersLeft[random.Next() % playersLeft.Count];
			int looserIndex = random.Next()% playersLeft.Count;
			int blindIndex = looserIndex+1;
			if (blindIndex >= playersLeft.Count)
			{
				blindIndex = 0;
			}
			Participant blind = (Participant)playersLeft[blindIndex];
			Participant looser = (Participant)playersLeft[looserIndex];
			if (blind != winner && blind != looser)
			{
				if (blind.Chips > blindLevel)
				{
					winner.Chips += blindLevel;
					blind.Chips -= blindLevel;
				}
				else
				{
					winner.Chips += blind.Chips;
					blind.Chips = 0;
					knockedOut(blind);
				}
			}
			if (looser.Chips > averagePotSize*blindLevel && winner.Chips > averagePotSize*blindLevel)
			{
				winner.Chips += averagePotSize*blindLevel;
				looser.Chips -= averagePotSize*blindLevel;
				if (looser.Chips < 0)
					throw(new SystemException("negative chips"));
			}
			else if (looser.Chips > winner.Chips)
			{
				looser.Chips -= winner.Chips;
				winner.Chips += winner.Chips;
				if (looser.Chips < 0)
					throw(new SystemException("negative chips"));
			}
			else
			{
				winner.Chips += looser.Chips;
				looser.Chips = 0;
				if (looser.Chips < 0)
					throw(new SystemException("negative chips"));
				knockedOut(looser);
			} 		
		}


		private void setupTornament(ArrayList PlayersLeft)
		{
			blindLevel = 14;
			handsCurrentLevel = 0;

			foreach (Participant player in PlayersLeft)
			{
				player.Chips = player.StartingChips;
			}
		}
		private void knockedOut(Participant bustedPlayer)
		{
			if (playersLeft.Count <= (int)prizeStructure.Length )
			{
				bustedPlayer.bustedOut(playersLeft.Count, (int)prizeStructure[playersLeft.Count - 1]);
			}
			else
			{
				bustedPlayer.bustedOut(playersLeft.Count, 0);
			}
			playersLeft.Remove(bustedPlayer);
		}

		private void displayResults(ArrayList participants, int numSimulations)
		{
			StreamWriter sw = null;
			string filename = "C:\\Poker\\Software\\TornementSim.txt";
			try
			{
				if (File.Exists(filename))
				{
					File.Delete(filename);
				}
				sw = File.CreateText(filename);
				sw.WriteLine("Number of sims {0}, Number of player {1}",numSimulations, participants.Count); 
				foreach ( Participant player in participants )
				{
					sw.WriteLine("Starting Chips {0}\t Torneamnt EV = {1}\t  Reduction factor = {2}", 
						player.StartingChips, 
						player.EV, 
						player.EV/player.StartingChips);
				}
			}
			catch( Exception e)
			{
				MessageBox.Show(e.Message);
			}
			finally
			{
				if(sw != null)
				{
					sw.Close();
				}
			}

			StreamWriter swData = null;
			string filenameData = "C:\\Poker\\Software\\TornementSimData.txt";
			try
			{
				if (File.Exists(filenameData))
				{
					File.Delete(filenameData);
				}
				swData = File.CreateText(filenameData);
				foreach ( Participant player in participants )
				{
					swData.WriteLine("{0}\t{1}", 
						(float)player.StartingChips/startingChips, 
						player.EV/player.StartingChips);
				}
			}
			catch( Exception e)
			{
				MessageBox.Show(e.Message);
			}
			finally
			{
				if(swData != null)
				{
					swData.Close();
				}
			}
		}

		private int blindLevel = 1;
		private Random random = new Random();
		private int averagePotSize = 5;
		private int handsCurrentLevel = 0;
		private ArrayList playersLeft;
		//private long[] prizeStructure = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
		private long[] prizeStructure = {3000,2000,1000,800,600,500,400,300,200,200,
										100,100,100,100,100,100,100,100,100,100};
		private long startingChips = 100;

	}
}
