
# Constants
MENU_COLWIDTH = 40

#*******************************************************************************
# printIndexedList
#
# description: This function takes a list and an optional prompt as input. It
#              prints the elements of the list along with their indices in a
#              formatted way. If a prompt is provided, it's displayed as a
#              header above the list.
#
# input: lst - The list to be printed.
#        prompt - An optional prompt to be displayed as a header.
#
# output: The function displays the list along with indices to the console.
#
# parameters: 
#   - lst: The list to be printed.
#   - prompt (optional): A string used as a header for the list display.
#
# returns: None
#*******************************************************************************
def printIndexedList(lst, prompt=""):
  if prompt:
      listHeader = f"[{prompt:{'='}^{MENU_COLWIDTH}}]"
      print(f"\n{listHeader}")

  index = 0
  while index < len(lst):
      print(f"[{index}] {lst[index]}")
      index += 1

#*******************************************************************************
# validateMenuChoice
#
# description: This function takes a prompt and the number of menu options as
#              input. It validates the user's menu choice, ensuring it's within
#              the valid range.
#
# input: prompt - The prompt to ask the user for their menu choice.
#        numOptions - The number of menu options.
#
# output: The function takes user input and ensures it's a valid menu choice.
#
# parameters: 
#   - prompt: The prompt to ask the user for their menu choice.
#   - numOptions: The number of menu options available.
#
# returns: The user's validated menu choice as an integer.
#*******************************************************************************
def validateMenuChoice(prompt, numOptions): 
  choice = int(input(prompt))
  notValid = (choice < 0 or choice > numOptions)
 
    
  while notValid:
    print(f'Invalid input. Please make a selection amongst the available options.\
Select an option (0 to {numOptions - 1}).')
    choice = int(input(prompt))
    notValid = (choice < 0 or choice > numOptions)
  return choice


#*******************************************************************************
# validateMenuChoice
#
# description: This function takes a prompt and the number of menu options as
#              input. It validates the user's menu choice, ensuring it's within
#              the valid range.
#
# input: prompt - The prompt to ask the user for their menu choice.
#        numOptions - The number of menu options.
#
# output: The function takes user input and ensures it's a valid menu choice.
#
# parameters: 
#   - prompt: The prompt to ask the user for their menu choice.
#   - numOptions: The number of menu options available.
#
# returns: The user's validated menu choice as an integer.
#*******************************************************************************
def validateTextMenuChoice(prompt, optionsList): 
  choice = input(prompt).upper()
  notValid = choice not in optionsList
  while notValid:
    print("Invalid input. Please make a selection amongst the available options.\n\
The options available are: ", end = "")
    for option in optionsList:
      print(option, end = " ")

    choice = input(prompt).upper()
    notValid = choice not in optionsList
  
  return choice


#*******************************************************************************
# displayMenu
#
# description: This function takes a prompt and a list of menu options as input,
#              along with optional flags to display "Exit" and "Back to Main Menu"
#              options. It displays a menu to the user, listing the menu options
#              along with their indices.
#
# input: prompt - The prompt to be displayed above the menu.
#        menuOptionsList - A list of menu options.
#        displayExit (optional) - If True, adds an "Exit" option to the menu.
#        displayMenuReturn (optional) - If True, adds a "Back to Main Menu" option
#                                      to the menu.
#
# output: The function displays the menu options to the console.
#
# parameters: 
#   - prompt: The prompt to be displayed above the menu.
#   - menuOptionsList: A list of menu options.
#   - displayExit (optional): If True, adds an "Exit" option to the menu.
#   - displayMenuReturn (optional): If True, adds a "Back to Main Menu" option
#                                  to the menu.
#
# returns: None
#*******************************************************************************
def displayMenu(prompt, menuOptionsList, displayExit = False, displayMenuReturn = False):
  if displayMenuReturn:
    menuOptionsList.append("Back to Main Menu")
    printIndexedList(menuOptionsList, prompt)
  elif displayExit:
    menuOptionsList.append("Exit")
    printIndexedList(menuOptionsList, prompt)
  else:
    printIndexedList(menuOptionsList, prompt)

#*******************************************************************************
# displayExitableMenu
#
# description: This function is an abstraction that invokes the displayMenu
#              function with the addition of an "Exit" option in the menu.
#
# input: prompt - The prompt to be displayed above the menu.
#        menuOptionsList - A list of menu options.
#
# output: The function displays the menu options along with an "Exit" option
#         to the console.
#
# parameters: 
#   - prompt: The prompt to be displayed above the menu.
#   - menuOptionsList: A list of menu options.
#
# returns: None
#*******************************************************************************
def displayExitableMenu(prompt, menuOptionsList):
  displayMenu(prompt, menuOptionsList, displayExit=True)


#*******************************************************************************
# displayReturnableMenu
#
# description: This function is an abstraction that invokes the displayMenu
#              function with the addition of a "Back to Main Menu" option in
#              the menu.
#
# input: prompt - The prompt to be displayed above the menu.
#        menuOptionsList - A list of menu options.
#
# output: The function displays the menu options along with a "Back to Main Menu"
#         option to the console.
#
# parameters: 
#   - prompt: The prompt to be displayed above the menu.
#   - menuOptionsList: A list of menu options.
#
# returns: None
#*******************************************************************************
def displayReturnableMenu(prompt, menuOptionsList):
  displayMenu(prompt, menuOptionsList, displayMenuReturn=True)


#*******************************************************************************
# validateInputIsNumerical
#
# description: This function takes a prompt as input and repeatedly asks the user
#              for input until a valid numerical value is provided. It handles
#              non-numeric input and provides an error message.
#
# input: prompt - The prompt to ask the user for numerical input.
#
# output: The function takes user input, validates it as a numerical value, and
#         provides an error message for non-numeric input.
#
# parameters: 
#   - prompt: The prompt to ask the user for numerical input.
#
# returns: The validated numerical value as a float.
#*******************************************************************************
def validateInputIsNumerical(prompt):
  notANumber = True
  number = 0
  
  while notANumber:
    inputValue = input(prompt)

    try: 
      number = float(inputValue)
      notANumber = False
    except ValueError:
      print("[ERROR]: Not a valid number. Please try again.\n")

  return number


