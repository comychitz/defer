#ifndef _DEFER_H_
#define _DEFER_H_

/**
 * template class definition (forward declared)
 */
template <typename>
class Defer;

/**
 * Defer a function that returns any type and takes no arguments.
 * Uses template specialization (a specific implementation when given a specific
 * type) to implement calling the function that is being deferred.
 */
template <typename Return>
class Defer<Return (&)()>
{
  public:
    Defer(Return (*f)()) 
      : f_(f)
    {
    }

    ~Defer()
    {
      if(f_)
      {
        (void)f_();
      }
    }

  private:
    Defer(const Defer&);
    Return (*f_)();
};

/**
 * Defer a function that returns any type and takes 1 argument.
 */
template <typename Return, typename ParamA>
class Defer<Return (&)(ParamA)>
{
  public:
    Defer(Return (*f)(ParamA), ParamA pA) 
      : f_(f), pA_(pA)
    {
    }

    ~Defer()
    {
      if(f_)
      {
        (void)f_(pA_);
      }
    }

  private:
    Defer(const Defer&);
    Return (*f_)(ParamA);
    ParamA pA_;
};

/**
 * Defer a function that returns any type and takes 2 arguments.
 */
template <typename Return, typename ParamA, typename ParamB>
class Defer<Return (&)(ParamA, ParamB)>
{
  public:
    Defer(Return (*f)(ParamA, ParamB), ParamA pA, ParamB pB) 
      : f_(f), pA_(pA), pB_(pB)
    {
    }

    ~Defer()
    {
      if(f_)
      {
        (void)f_(pA_, pB_);
      }
    }

  private:
    Defer(const Defer&);
    Return (*f_)(ParamA, ParamB);
    ParamA pA_;
    ParamB pB_;
};

/**
 * Defer a function that returns any type and takes 3 arguments.
 */
template <typename Return, typename ParamA, typename ParamB, typename ParamC>
class Defer<Return (&)(ParamA, ParamB, ParamC)>
{
  public:
    Defer(Return (*f)(ParamA, ParamB, ParamC), ParamA pA, ParamB pB, ParamC pC) 
      : f_(f), pA_(pA), pB_(pB), pC_(pC)
    {
    }

    ~Defer()
    {
      if(f_)
      {
        (void)f_(pA_, pB_, pC_);
      }
    }

  private:
    Defer(const Defer&);
    Return (*f_)(ParamA, ParamB, ParamC);
    ParamA pA_;
    ParamB pB_;
    ParamC pC_;
};

/**
 * Defer a function that returns any type and takes 4 arguments.
 */
template <typename Return, typename ParamA, typename ParamB, typename ParamC, typename ParamD>
class Defer<Return (&)(ParamA, ParamB, ParamC, ParamD)>
{
  public:
    Defer(Return (*f)(ParamA, ParamB, ParamC, ParamD), ParamA pA, ParamB pB, ParamC pC, ParamD pD) 
      : f_(f), pA_(pA), pB_(pB), pC_(pC), pD_(pD)
    {
    }

    ~Defer()
    {
      if(f_)
      {
        (void)f_(pA_, pB_, pC_, pD_);
      }
    }

  private:
    Defer(const Defer&);
    Return (*f_)(ParamA, ParamB, ParamC, ParamD);
    ParamA pA_;
    ParamB pB_;
    ParamC pC_;
    ParamD pD_;
};

/**
 * Defer a function that returns any type and takes 5 arguments.
 */
template <typename Return, typename ParamA, typename ParamB, typename ParamC, typename ParamD, typename ParamE>
class Defer<Return (&)(ParamA, ParamB, ParamC, ParamD, ParamE)>
{
  public:
    Defer(Return (*f)(ParamA, ParamB, ParamC, ParamD, ParamE), ParamA pA, ParamB pB, ParamC pC, ParamD pD, ParamE pE) 
      : f_(f), pA_(pA), pB_(pB), pC_(pC), pD_(pD), pE_(pE)
    {
    }

    ~Defer()
    {
      if(f_)
      {
        (void)f_(pA_, pB_, pC_, pD_, pE_);
      }
    }

  private:
    Defer(const Defer&);
    Return (*f_)(ParamA, ParamB, ParamC, ParamD, ParamE);
    ParamA pA_;
    ParamB pB_;
    ParamC pC_;
    ParamD pD_;
    ParamE pE_;
};

#endif
