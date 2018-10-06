#include "security_settings.h"
#include <iostream>
#include <string>

template<typename T>
void print_var(const std::string& name, T value) noexcept {
	std::cout << name << " = " << value << std::endl;
}

SecuritySettings::SecuritySettings(unsigned long int lambda) : lambda(lambda), 
	gamma ( lambda*lambda*lambda*lambda*lambda),
    eta( lambda*lambda * ( ceil( log2( lambda*lambda ) ) )),
	rho(lambda),
	rho_(2*lambda),
	tau(gamma + lambda),
	kappa(gamma*eta/rho_), // WARNING: This may need to be ceiling instead of floor
	theta(lambda),
	big_theta(kappa*lambda)
{
  //tau = 1000 + lambda;
  //big_theta = 100*lambda;

  private_key_length = theta;
  public_key_old_key_length = tau+1;
  public_key_y_vector_length = big_theta;

  print_var("gamma", gamma);
  print_var("eta", eta);
  print_var("rho", rho);
  print_var("rho_", rho_);
  print_var("tau", tau);
  print_var("kappa", kappa);
  print_var("theta", theta);
  print_var("big_theta", big_theta);
}

