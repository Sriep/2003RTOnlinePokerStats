using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using PokerTornamentSim;

namespace PokerTornamentSim
{
	/// <summary>
	/// Summary description for TornamentParamaters.
	/// </summary>
	public class TornamentParamaters : System.Windows.Forms.Form
	{
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox numParticipants;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button doSims;
		private System.Windows.Forms.TextBox numberSims;
		private System.Windows.Forms.Button torParmsCancel;
		private System.Windows.Forms.ComboBox comboPrizeStructure;
		private System.Windows.Forms.ComboBox comboBlindStructure;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label5;
		private System.Data.Odbc.OdbcDataAdapter odbcDataAdapterBlinds;
		private System.Data.Odbc.OdbcCommand odbcSelectCommand1;
		private System.Data.Odbc.OdbcCommand odbcInsertCommand1;
		private System.Data.Odbc.OdbcConnection odbcConnectionBlinds;
		private System.Data.Odbc.OdbcDataAdapter odbcDataAdapterPrizes;
		private System.Data.Odbc.OdbcCommand odbcSelectCommand2;
		private System.Data.Odbc.OdbcCommand odbcInsertCommand2;
		private System.Data.Odbc.OdbcConnection odbcConnectionPrizes;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.TextBox averageStack;
		private System.Windows.Forms.ProgressBar progressBar;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public TornamentParamaters()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.numParticipants = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.numberSims = new System.Windows.Forms.TextBox();
			this.doSims = new System.Windows.Forms.Button();
			this.torParmsCancel = new System.Windows.Forms.Button();
			this.comboPrizeStructure = new System.Windows.Forms.ComboBox();
			this.comboBlindStructure = new System.Windows.Forms.ComboBox();
			this.label3 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.odbcDataAdapterBlinds = new System.Data.Odbc.OdbcDataAdapter();
			this.odbcInsertCommand1 = new System.Data.Odbc.OdbcCommand();
			this.odbcConnectionBlinds = new System.Data.Odbc.OdbcConnection();
			this.odbcSelectCommand1 = new System.Data.Odbc.OdbcCommand();
			this.odbcDataAdapterPrizes = new System.Data.Odbc.OdbcDataAdapter();
			this.odbcInsertCommand2 = new System.Data.Odbc.OdbcCommand();
			this.odbcSelectCommand2 = new System.Data.Odbc.OdbcCommand();
			this.odbcConnectionPrizes = new System.Data.Odbc.OdbcConnection();
			this.label6 = new System.Windows.Forms.Label();
			this.averageStack = new System.Windows.Forms.TextBox();
			this.progressBar = new System.Windows.Forms.ProgressBar();
			this.SuspendLayout();
			// 
			// numParticipants
			// 
			this.numParticipants.Location = new System.Drawing.Point(352, 16);
			this.numParticipants.Name = "numParticipants";
			this.numParticipants.TabIndex = 1;
			this.numParticipants.Text = "20";
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(224, 16);
			this.label1.Name = "label1";
			this.label1.TabIndex = 2;
			this.label1.Text = "Number of Players";
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(224, 56);
			this.label2.Name = "label2";
			this.label2.TabIndex = 2;
			this.label2.Text = "Number of Sims";
			// 
			// numberSims
			// 
			this.numberSims.Location = new System.Drawing.Point(352, 56);
			this.numberSims.Name = "numberSims";
			this.numberSims.TabIndex = 1;
			this.numberSims.Text = "20000";
			// 
			// doSims
			// 
			this.doSims.Location = new System.Drawing.Point(48, 136);
			this.doSims.Name = "doSims";
			this.doSims.Size = new System.Drawing.Size(104, 23);
			this.doSims.TabIndex = 5;
			this.doSims.Text = "Do Simulation";
			this.doSims.Click += new System.EventHandler(this.doSims_Click);
			// 
			// torParmsCancel
			// 
			this.torParmsCancel.Location = new System.Drawing.Point(200, 136);
			this.torParmsCancel.Name = "torParmsCancel";
			this.torParmsCancel.TabIndex = 6;
			this.torParmsCancel.Text = "Cancel";
			this.torParmsCancel.Click += new System.EventHandler(this.torParmsCancel_Click);
			// 
			// comboPrizeStructure
			// 
			this.comboPrizeStructure.Location = new System.Drawing.Point(16, 40);
			this.comboPrizeStructure.Name = "comboPrizeStructure";
			this.comboPrizeStructure.Size = new System.Drawing.Size(168, 21);
			this.comboPrizeStructure.TabIndex = 7;
			this.comboPrizeStructure.Text = "comboBox1";
			// 
			// comboBlindStructure
			// 
			this.comboBlindStructure.Location = new System.Drawing.Point(16, 96);
			this.comboBlindStructure.Name = "comboBlindStructure";
			this.comboBlindStructure.Size = new System.Drawing.Size(168, 21);
			this.comboBlindStructure.TabIndex = 8;
			this.comboBlindStructure.Text = "comboBox2";
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(16, 16);
			this.label3.Name = "label3";
			this.label3.TabIndex = 9;
			this.label3.Text = "Prize structure";
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(16, 72);
			this.label5.Name = "label5";
			this.label5.TabIndex = 10;
			this.label5.Text = "Blind Structure";
			// 
			// odbcDataAdapterBlinds
			// 
			this.odbcDataAdapterBlinds.InsertCommand = this.odbcInsertCommand1;
			this.odbcDataAdapterBlinds.SelectCommand = this.odbcSelectCommand1;
			this.odbcDataAdapterBlinds.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
																											new System.Data.Common.DataTableMapping("Table", "BlindStructure", new System.Data.Common.DataColumnMapping[] {
																																																							  new System.Data.Common.DataColumnMapping("BlindStructureID", "BlindStructureID"),
																																																							  new System.Data.Common.DataColumnMapping("Name", "Name")})});
			// 
			// odbcInsertCommand1
			// 
			this.odbcInsertCommand1.CommandText = "INSERT INTO BlindStructure(Name) VALUES (?)";
			this.odbcInsertCommand1.Connection = this.odbcConnectionBlinds;
			this.odbcInsertCommand1.Parameters.Add(new System.Data.Odbc.OdbcParameter("Name", System.Data.Odbc.OdbcType.NVarChar, 50, "Name"));
			// 
			// odbcConnectionBlinds
			// 
			this.odbcConnectionBlinds.ConnectionString = "MaxBufferSize=2048;FIL=MS Access;DSN=TornamentSimData;PageTimeout=5;DBQ=B:\\PokerT" +
				"ornamentSim\\PokerTornamentSim\\TornamentSimData.mdb;DriverId=25";
			// 
			// odbcSelectCommand1
			// 
			this.odbcSelectCommand1.CommandText = "SELECT BlindStructureID, Name FROM BlindStructure";
			this.odbcSelectCommand1.Connection = this.odbcConnectionBlinds;
			// 
			// odbcDataAdapterPrizes
			// 
			this.odbcDataAdapterPrizes.InsertCommand = this.odbcInsertCommand2;
			this.odbcDataAdapterPrizes.SelectCommand = this.odbcSelectCommand2;
			this.odbcDataAdapterPrizes.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
																											new System.Data.Common.DataTableMapping("Table", "PrizeStructures", new System.Data.Common.DataColumnMapping[] {
																																																							   new System.Data.Common.DataColumnMapping("PrizeStructureId", "PrizeStructureId"),
																																																							   new System.Data.Common.DataColumnMapping("Name", "Name")})});
			// 
			// odbcInsertCommand2
			// 
			this.odbcInsertCommand2.CommandText = "INSERT INTO PrizeStructures(Name) VALUES (?)";
			this.odbcInsertCommand2.Connection = this.odbcConnectionBlinds;
			this.odbcInsertCommand2.Parameters.Add(new System.Data.Odbc.OdbcParameter("Name", System.Data.Odbc.OdbcType.NVarChar, 50, "Name"));
			// 
			// odbcSelectCommand2
			// 
			this.odbcSelectCommand2.CommandText = "SELECT PrizeStructureId, Name FROM PrizeStructures";
			this.odbcSelectCommand2.Connection = this.odbcConnectionBlinds;
			// 
			// odbcConnectionPrizes
			// 
			this.odbcConnectionPrizes.ConnectionString = "MaxBufferSize=2048;FIL=MS Access;DSN=TornamentSimData;PageTimeout=5;DBQ=B:\\PokerT" +
				"ornamentSim\\PokerTornamentSim\\TornamentSimData.mdb;DriverId=25";
			// 
			// label6
			// 
			this.label6.Location = new System.Drawing.Point(224, 88);
			this.label6.Name = "label6";
			this.label6.TabIndex = 11;
			this.label6.Text = "Average Stack";
			// 
			// averageStack
			// 
			this.averageStack.Location = new System.Drawing.Point(352, 88);
			this.averageStack.Name = "averageStack";
			this.averageStack.TabIndex = 12;
			this.averageStack.Text = "100";
			// 
			// progressBar
			// 
			this.progressBar.Location = new System.Drawing.Point(16, 168);
			this.progressBar.Name = "progressBar";
			this.progressBar.Size = new System.Drawing.Size(424, 23);
			this.progressBar.TabIndex = 13;
			// 
			// TornamentParamaters
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(464, 205);
			this.Controls.Add(this.progressBar);
			this.Controls.Add(this.averageStack);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.comboBlindStructure);
			this.Controls.Add(this.comboPrizeStructure);
			this.Controls.Add(this.torParmsCancel);
			this.Controls.Add(this.doSims);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.numParticipants);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.numberSims);
			this.Name = "TornamentParamaters";
			this.Text = "Tornament Paramaters";
			this.Load += new System.EventHandler(this.TornamentParamaters_Load);
			this.ResumeLayout(false);

		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new TornamentParamaters());
		}

		private void TornamentParamaters_Load(object sender, System.EventArgs e)
		{
		
		}

		private void doSims_Click(object sender, System.EventArgs e)
		{
			TornamentSim simModel = new TornamentSim();
			simModel.DoMultipleTournamentSims(int.Parse(this.numParticipants.Text),
											  int.Parse(this.numberSims.Text),
											  int.Parse(this.averageStack.Text),
											  progressBar);
		}

		private void torParmsCancel_Click(object sender, System.EventArgs e)
		{
			//close();
		}

		private void sqlConnection1_InfoMessage(object sender, System.Data.SqlClient.SqlInfoMessageEventArgs e)
		{
		
		}

		private void dataView1_ListChanged(object sender, System.ComponentModel.ListChangedEventArgs e)
		{
		
		}

		private void odbcDataAdapter1_RowUpdated(object sender, System.Data.Odbc.OdbcRowUpdatedEventArgs e)
		{
		
		}

		private void odbcConnection1_InfoMessage(object sender, System.Data.Odbc.OdbcInfoMessageEventArgs e)
		{
		
		}

	}
}
