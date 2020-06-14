#ifndef __MODULE_MEMLEAKS_H__
#define __MODULE_MEMLEAKS_H__

#include "Module.h"

//Warning: This class is merely for debugging purposes.
//It would not exist per se in a professional game engine.
//The logic from this class would be a part of a bigger class.

class ModuleDebugInfo : public Module
{
public:
	//Constructor
	ModuleDebugInfo(bool startEnabled);

	// Destructor
	~ModuleDebugInfo();

	// Called on application start.
	// Loads the font used for debugging purposes
	bool Start() override;

	// Called on application exit.
	// Unloads the font
	bool CleanUp() override;

	// Called at the middle of the application loop
	// Switches debug info depending on input
	update_status Update() override;

	// Called at the end of the application loop
	// Renders all the debug text info
	update_status PostUpdate() override;

	// Displays the active and total resources from the selected module
	void DrawModuleResources(Module* module);

private:
	bool debugMemLeaks = false;
	Module* inspectedModule = nullptr;
	
	int debugFont = -1;
	char debugText[150] = { "\0" };
};

#endif //!__MODULE_MEMLEAKS_H__