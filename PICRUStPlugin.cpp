#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "PICRUStPlugin.h"

void PICRUStPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
   }
}

void PICRUStPlugin::run() {
   
}

void PICRUStPlugin::output(std::string file) {
 std::string command = "metagenome_pipeline.py -i "+parameters["abundances"]+" -f "+parameters["functions"]+" -m "+parameters["markers"]+" --max_nsti "+parameters["max_nsti"]+" -o "+file;
 std::cout << command << std::endl;
 system(command.c_str());
 command = std::string("gunzip ")+std::string(PluginManager::prefix())+std::string("/seqtab_norm.tsv.gz");
 system(command.c_str());
 command = std::string("gunzip ")+std::string(PluginManager::prefix())+std::string("/pred_metagenome_unstrat.tsv.gz");
 system(command.c_str());
}

PluginProxy<PICRUStPlugin> PICRUStPluginProxy = PluginProxy<PICRUStPlugin>("PICRUSt", PluginManager::getInstance());
