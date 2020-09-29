//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "kksm_03TestApp.h"
#include "kksm_03App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
kksm_03TestApp::validParams()
{
  InputParameters params = kksm_03App::validParams();
  return params;
}

kksm_03TestApp::kksm_03TestApp(InputParameters parameters) : MooseApp(parameters)
{
  kksm_03TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

kksm_03TestApp::~kksm_03TestApp() {}

void
kksm_03TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  kksm_03App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"kksm_03TestApp"});
    Registry::registerActionsTo(af, {"kksm_03TestApp"});
  }
}

void
kksm_03TestApp::registerApps()
{
  registerApp(kksm_03App);
  registerApp(kksm_03TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
kksm_03TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kksm_03TestApp::registerAll(f, af, s);
}
extern "C" void
kksm_03TestApp__registerApps()
{
  kksm_03TestApp::registerApps();
}
