#include <iostream>
#include <string>
using namespace std;


class GraphicAdapter
{
public:
	void GoodbuyeDisplay()
	{
		cout << "4.Goodbuye Display\n";
	}
	void DisplayHDDdata()
	{
		cout << "20.Display HDD data\n";
	}
	void DisplayRAMdata()
	{
		cout << "12.Display RAM data\n";
	}
	void DisplayDVD_ROMdata()
	{
		cout << "16.Display DVD-ROM data\n";
	}
	void Execution()
	{
		cout << "6.Graphhic Adapter execution\n";
	}
	void MonitorConectionCheck()
	{
		cout << "7.Monitor Conection Check\n";
	}
};

class RAM
{
public:
	void RAManalysis()
	{
		cout << "3.RAM analysis\n";
	}
	void RAMclear()
	{
		cout << "2.RAM clear\n";
	}
	void ExecuteDevices()
	{
		cout << "10.Execute devices\n";
	}

	void MemoryAnalysis()
	{
		cout << "11.MemoryAnalysis\n";
	}
};

class HDD
{
public:
	void Off()
	{
		cout << "1.HDD off\n";
	}
	void Execute()
	{
		cout << "18.Execute HDD\n";
	}
	void BootSectorCheck()
	{
		cout << "19.Boot Sector Check\n";
	}
};

class DVD_ROM
{
public:
	void DefaultPosition()
	{
		cout << "5.Default Position\n";
	}
	void ExecuteDVD_ROM()
	{
		cout << "14.Execute DVD-ROM\n";
	}
	void ExistanceCheck()
	{
		cout << "15.DVD disk existance check\n";
	}
};

class PowerSupply
{
public:
	void PCPowerOff()
	{
		cout << "11.PC Power off\n";
	}
	void GraphicAdapterPowerOff()
	{
		cout << "6.Graphic Adapter Power Off\n";
	}
	void HDDPowerOff()
	{
		cout << "9.HDD Power Off\n";
	}
	void RAMPowerOff()
	{
		cout << "7.RAM Power Off\n";
	}
	void DVD_ROMPowerOff()
	{
		cout << "8.DVD-ROM Power Off\n";
	}
	void PowerToRAM()
	{
		cout << "9. Power to the RAM\n";
	}
	void PowerToGraphicAdapter()
	{
		cout << "5. Power to the Graphic Adapter\n";
	}
	void PowerToHDD()
	{
		cout << "17. Power to the HDD\n";
	}
	void PowerToDVD_ROM()
	{
		cout << "13. Power to the DVD ROM\n";
	}
	void PowerToPC()
	{
		cout << "1.Power to the Personal computer\n";
	}
};


class Sensors
{
public:

	void VoltageCheck()
	{
		cout << "2.Voltage Check\n";
	}
	void PowerSupplyTemperatureCheck()
	{
		cout << "3.PowerSupplyTemperatureCheck\n";
	}
	void GraphicAdapterTemperatureCheck()
	{
		cout << "4.Graphic Adapter Temperature Check\n";
	}
	void RAMtemperatureCheck()
	{
		cout << "8.RAM Temperature Check\n";
	}
	void AllDevicesTemperatureCheck()
	{
		cout << "21.All Devices Temperature Check\n";
	}
};


class PCFacade
{
	GraphicAdapter ga;
	RAM ram;
	HDD hdd;
	DVD_ROM dvd;
	PowerSupply power;
	Sensors sn;
public:
	PCFacade(GraphicAdapter ga, RAM ram, HDD hdd, DVD_ROM dvd, PowerSupply power, Sensors sn)
	{
		ga = ga;
		ram = ram;
		hdd = hdd;
		dvd = dvd;
		power = power;
		sn = sn;
	}
	void BeginWork()
	{
		power.PowerToPC();
		sn.VoltageCheck();
		sn.PowerSupplyTemperatureCheck();
		sn.GraphicAdapterTemperatureCheck();
		power.PowerToGraphicAdapter();
		ga.Execution();
		ga.MonitorConectionCheck();
		sn.RAMtemperatureCheck();
		power.PowerToRAM();
		ram.ExecuteDevices();
		ram.MemoryAnalysis();
		ga.DisplayRAMdata();
		power.PowerToDVD_ROM();
		dvd.ExecuteDVD_ROM();
		dvd.ExistanceCheck();
		ga.DisplayDVD_ROMdata();
		power.PowerToHDD();
		hdd.Execute();
		hdd.BootSectorCheck();
		ga.DisplayHDDdata();
		sn.AllDevicesTemperatureCheck();
		
	}
	void EndWork()
	{

		hdd.Off();
		ram.RAMclear();
		ram.RAManalysis();
		ga.GoodbuyeDisplay();
		dvd.DefaultPosition();
		power.GraphicAdapterPowerOff();
		power.RAMPowerOff();
		power.DVD_ROMPowerOff();
		power.HDDPowerOff();
		sn.VoltageCheck();
		power.PCPowerOff();
	}
};

// Фасад предоставляет клиенту интерфейс более высокого уровня, который упрощает использование подсистемы.
class PC_User
{
public:
	void CreateApplication(PCFacade facade)
	{
		facade.BeginWork();
		system("pause");
		facade.EndWork();
	}
};

int main()
{
	GraphicAdapter ga;
	RAM ram;
	HDD hdd;
	DVD_ROM dvd;
	PowerSupply power;
	Sensors sn;

	PCFacade ide(ga, ram, hdd,dvd,power,sn);

	PC_User user;
	user.CreateApplication(ide);

	system("pause");
	return 0;
}
