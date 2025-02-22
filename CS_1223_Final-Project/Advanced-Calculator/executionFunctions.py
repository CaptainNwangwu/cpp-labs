from mathFunctions import *


EXIT_KEYWORD = "exit"
YES_NO_TUPLE = ["Y", "YES", "N", "NO"]

#*******************************************************************************
# exitConfirmation
#
# description: This function asks the user for confirmation before exiting a
#              specific mode or the entire program. It displays a message
#              and waits for a "Y" (yes) or "N" (no) input from the user.
#
# input: The function takes user input to confirm whether they wish to exit.
#
# output: The function provides the user with an exit confirmation message and
#         returns their choice.
#
# parameters: None
#
# returns: 
#   - True if the user chooses to exit ("Y" for yes).
#   - False if the user chooses not to exit ("N" for no).
#*******************************************************************************
def exitConfirmation():
  exitConfirmMsg = "Are you sure you wish to exit?[Y/N]: "

  choice = validateTextMenuChoice(exitConfirmMsg, YES_NO_TUPLE)

  return choice == "Y" or choice == "YES"



#*******************************************************************************
# confirmMainMenuReturn
#
# description: This function asks the user for confirmation before returning to
#              the main menu from a specific mode. It displays a message and
#              waits for a "Y" (yes) or "N" (no) input from the user.
#
# input: The function takes user input to confirm whether they wish to return to
#        the main menu.
#
# output: The function provides the user with a return confirmation message and
#         returns their choice.
#
# parameters: None
#
# returns: 
#   - True if the user chooses to return to the main menu ("Y" for yes).
#   - False if the user chooses not to return to the main menu ("N" for no).
#*******************************************************************************
def confirmMainMenuReturn():
  mainMenuReturnMsg = "Are you sure you wish to return to the main menu?[Y/N]: "

  choice = validateTextMenuChoice(mainMenuReturnMsg, YES_NO_TUPLE)

  return choice == "Y" or choice == "YES"



#*******************************************************************************
# executeArithmeticExpressionMode
#
# description: This function allows the user to perform arithmetic calculations
#              in a loop. It takes user input expressions, evaluates them, and
#              keeps track of the result. The user can exit the mode by typing
#              the EXIT_KEYWORD.
#
# input: This function takes user input expressions as strings. It checks if the
#        expression contains the EXIT_KEYWORD to exit the mode.
#
# output: The function produces arithmetic calculation results and stores the
#         most recent answer in the 'ans' variable.
#
# parameters: None
#
# returns: This function doesn't return a value.
#*******************************************************************************
def executeArithmeticExpressionMode():
  
  INPUT_INDICATOR_CHAR = f"\nEnter Expression(Enter {EXIT_KEYWORD} to stop)-->: "
  finishedExecuting = False

  ans = 0
  while not finishedExecuting:
    recentAns = ans
    expression = input(INPUT_INDICATOR_CHAR) # Get user input as string


    if expression == EXIT_KEYWORD:
      finishedExecuting = True
    else:

      # Check if "ans" is in the expression and replace it with the current
      # value of ans.

      if "ans" in expression:
        expression = expression.replace("ans", str(ans))

      # Evaluate the modified expression

      # If an error is found in the answer, store the most recent valid ans as ans instead
      result = safeEval(expression)
      ans = result
      errProneAns = str(ans)
      if "[ERROR]" in errProneAns:
        ans = recentAns
      print(result)



#*******************************************************************************
# executeTrigonometricCalculatorMode
#
# description: This function allows the user to perform trigonometric calculations
#              in a loop. It uses the 'promptTrigonometricCalculator' function to
#              guide the user in selecting a type of trigonometric calculation and
#              provides results. The user can choose to continue or exit the mode.
#
# input: This function takes user input to determine whether to continue performing
#        trigonometric calculations. It relies on the 'promptTrigonometricCalculator'
#        function for specific calculations.
#
# output: The function provides results of trigonometric calculations to the user
#         and gives the option to continue or exit the mode.
#
# parameters: None
#
# returns: This function doesn't return a value.
#*******************************************************************************
def executeTrigonometricCalculatorMode():
  finishedExecuting = False

  while not finishedExecuting:
    promptTrigonometricCalculator()

    continueConfirmPrompt = "\nDo you want to perform another calculation[Y/N]?: "
    confirmContinue = validateTextMenuChoice(continueConfirmPrompt, YES_NO_TUPLE)

    if confirmContinue == "N" or "NO":
      finishedExecuting = True



#*******************************************************************************
# executeMainMenu
#
# description: This function serves as the main menu for the calculator program.
#              It displays a list of available calculation modes, allows the user
#              to select one, and executes the chosen calculation mode. (For now, 
#              it provides Basic Arithmetic and Trigonometry).
#
# input: This function takes user input to select a calculation mode. It relies
#        on other functions for specific calculations.
#
# output: The function guides the user through the chosen calculation mode and
#         provides results as well as options to continue or exit the mode.
#
# parameters: None
#
# returns: This function doesn't return a value.
#*******************************************************************************
def executeMainMenu():
  mainMenuOptions = [
    "Basic Arithmetic",
    "Trigonometry"
  ]

  menuHeader = "Main Calculator Menu"
  menuSelectionPrompt = "\nPlease select your choice of calculation: "
  
  finishedExecuting = False
  while not finishedExecuting:
    displayExitableMenu(menuHeader, mainMenuOptions)
    selection = validateMenuChoice(menuSelectionPrompt,len(mainMenuOptions))
    print(f"You have selected {mainMenuOptions[selection]}.")

    mainMenuOptions.pop()
    if selection == 0: # Basic Arithmetic has been chosen.
      print("Type 'exit' to exit. Use 'ans' in expressions to use most recent answer.")
      executeArithmeticExpressionMode()
    elif selection == 1: # Trigonometry has been chosen.
      executeTrigonometricCalculatorMode()
    elif selection == len(mainMenuOptions): # Exit has been selected
      finishedExecuting = exitConfirmation()

  print("\nBye!")


    
  