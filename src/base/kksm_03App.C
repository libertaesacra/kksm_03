#include "kksm_03App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
kksm_03App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

kksm_03App::kksm_03App(InputParameters parameters) : MooseApp(parameters)
{
  kksm_03App::registerAll(_factory, _action_factory, _syntax);
}

kksm_03App::~kksm_03App() {}

void
kksm_03App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"kksm_03App"});
  Registry::registerActionsTo(af, {"kksm_03App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
kksm_03App::registerApps()
{
  registerApp(kksm_03App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
kksm_03App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kksm_03App::registerAll(f, af, s);
}
extern "C" void
kksm_03App__registerApps()
{
  kksm_03App::registerApps();
}
