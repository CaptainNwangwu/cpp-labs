import math
import re

from menuFunctions import *

# REGEX Pattern to match digits and valid arithmetic operators
VALID_ARITHMETIC_EXPRESS_PATTERN = r'\d+|[+\-*/%()]|\*\*'
'''
REGEX Expression Explanation:
  \d+              # Match one or more digits
  |                # OR 
  [+\-*/%()]       # Match one of the allowed operators:
                   #   +   Addition
                   #   -   Subtraction/Negation (handled by eval() )
                   #   *   Multiplication
                   #   /   Division
                   #   %   Modulus
                   #   (   Left parenthesis
                   #   )   Right parenthesis
  |                # OR
  \*\*             # Match the exponentiation operator (**) 
'''

DECIMAL_PRECISION = 4 # All calculated floats will be at 4 digits of precision for conciseness.

# Function to round a value to the specified decimal precision.
def setPrecision(value):
  return round(value, DECIMAL_PRECISION)

#*******************************************************************************
# isValidToken Function
#
# Description:  This function checks whether a given token (character or operator)
#               is a valid component of a basic arithmetic expression. 
#
#  Contextual Explanation: The intention is to "sanitize" the data input so that 
#  it can be used with the eval() function since manually parsing and evaluating 
#  arithmetic input seemed redundant for the scope of this problem, so I found it 
#  more practical to merely use menu input to ensure that the use of this function
#  in combination with eval() is used SOLELY with basic arithmetic expressions to 
#  limit the unsafety of the eval() function. For refernece, eval() evaluates a 
#  python expression, including mathematical ones. The only issue with this, 
#  however, is that if your input is not very tightly restricted a user can run
#  code than can be dangerous, hence why this extra "sanitation" is so important.
#
# Input: The input for this function is a token (a single character). It expects
# a string containing the token to be checked.
#
# Output: The output of this function is a boolean value. It returns True if the
# token is a valid component and False otherwise.
#
# Parameters:
# - token: The character to be checked for validity.
#
# returns: The function returns a boolean value, True if the token is valid and
# False if it is not.
#*******************************************************************************
def isValidToken(token):
  # Runs through an the entire pattern to check if token exists. (Match is found)
  return re.match(VALID_ARITHMETIC_EXPRESS_PATTERN, token) is not None


#*******************************************************************************
# tokenizeExpression Function
#
# Description: This function tokenizes an arithmetic expression by splitting it
# into valid components (tokens). It uses a regular expression to identify and 
# extract numbers, operators, and paranthesis.
#
# Input: The input for this function is a string containing the arithmetic expression
# to be tokenized.
#
# Output: The output of this function is a list of tokens extracted from the input
# expression. The tokens represent valid components of the arithmetic expression.
#
# Parameters:
# - expression: The arithmetic expression to be tokenized.
#
# Returns: The function returns a LIST of valid tokens that make up the arithmetic
# expression.
#*******************************************************************************
def tokenizeExpression(expression):
  return re.findall(VALID_ARITHMETIC_EXPRESS_PATTERN, expression)


#*******************************************************************************
# safeEval
#
# Description: The purpose behind this function is to invoke both the built in
# eval() function as well as the tokenizeExpression() function to ensure two 
# things:
#
# 1) Every character in the input stream is a number or valid operator.
# 2) The expression is a valid expression.
# 
# The use of both functions ensures sanitized input. In the event that both
# of these conditions are not met, an error message will be returned.
#
# Input: The input will be a string containing an arithmetic expression. The
# only valid operators are: 
#      (+)  Addition
#      (-)  Subtraction (as well as negation. Will be handled by eval())
#      (*)  Multiplication
#      (/) Division (as well as integer division. Handled by eval())
#      (**) Exponentiation
#      (%)  Modulus
#      
#      It will also find paranthesis valid.
# Output: The output will be the result of evaluating the expression 
# (if successful) or an error message (if the evaluation is unsuccessful)
#
# Parameters: 
# - expression: The arithematic expression to be evaluated.
#
# Returns: The function returns the result of the evaluation (a numerical value) if
# the expression is valid and can be safely evaluated. If there are invalid tokens
# or an evaluation error occurs, it returns an error message explaining the issue.
#*******************************************************************************
def safeEval(expression):
  tokens = tokenizeExpression(expression)
  err = ""
  result = ""

  # Vaidate each token
  if all(isValidToken(token) for token in tokens):
    # Once it has been confirmed all tokens are valid, we can 
    # safely evaluate the expression

    # Since we're relying on Python's interpreter evaluation critiera, to check 
    # for errors, using a try/except block with Python's built in exception 
    # handling is the most straight forward way to catch these errors. (I'm
    # most familiar with C++'s try/catch blocks, so this is a fairly easy
    # substitute.')
    try:
      evaluatedExpression = eval(expression)
      result = evaluatedExpression
    except ZeroDivisionError:
      err = "[ERROR]: Division by zero is illegal!\n"
    except SyntaxError:
      err = "[ERROR]: Invalid syntax. Please enter a valid expression.\n"
    except NameError:
      err = "[ERROR]: Non-numerical value used in the expression. \
Ensure that all operands are numbers.\n"

  # If an invalid token is found
  else:
    err = "[ERROR]: Unsupported operator used."
  # We then check if there is an error message (if err is empty), and return 
  if err:
    result = err

  return result




# {==========================Trigonometric Functions===========================}
#*******************************************************************************
# promptSin
#
# Description: This function interprets the result of finding the sine of a given angle
# via prompting the user for input. It calculates the sine using the formula: 
# sin(angle) = opposite / hypotenuse.
#
# Input: The function prompts the user to input the length of the side opposite to
# the angle (opposite) and the length of the hypotenuse. These values are used to
# calculate the sine.
#
# Output: The function returns the sine of the given angle, rounded to a specified
# decimal precision.
#
# Parameters:
# - opposite: The length of the side opposite to the angle.
# - hypotenuse: The length of the hypotenuse.
#
# Returns: The sine of the given angle, rounded to a specified decimal precision.
#*******************************************************************************
def promptSin():
    opposite = float(input("Please enter the length of the side opposite of theta (θ): "))
    hypotenuse = float(input("Please enter the side length of the hypotenuse: "))
    
    return setPrecision(opposite / hypotenuse)

#*******************************************************************************
# promptCos
#
# Description: This function interprets the result of finding the cosine of a given angle
# via prompting the user for input. It calculates the cosine using the formula: 
# cos(angle) = adjacent / hypotenuse.
#
# Input: The function prompts the user to input the length of the side adjacent to
# the angle (adjacent) and the length of the hypotenuse. These values are used to
# calculate the cosine.
#
# Output: The function returns the cosine of the given angle, rounded to a specified
# decimal precision.
#
# Parameters:
# - adjacent: The length of the side adjacent to the angle.
# - hypotenuse: The length of the hypotenuse.
#
# Returns: The cosine of the given angle, rounded to a specified decimal precision.
#*******************************************************************************
def promptCos():
  adjacent = float(input("Please enter the length of the side adjacent of theta (θ): "))
  hypotenuse = float(input("Please enter the side length of the hypotenuse: "))
  
  return setPrecision(adjacent / hypotenuse)

#*******************************************************************************
# promptTan
#
# Description: This function interprets the result of finding the tangent of a given angle
# via prompting the user for input. It calculates the tangent using the formula: 
# tan(angle) = opposite / adjacent.
#
# Input: The function prompts the user to input the length of the side opposite to
# the angle (opposite) and the length of the side adjacent to the angle (adjacent).
# These values are used to calculate the tangent.
#
# Output: The function returns the tangent of the given angle, rounded to a specified
# decimal precision.
#
# Parameters:
# - opposite: The length of the side opposite to the angle.
# - adjacent: The length of the side adjacent to the angle.
#
# Returns: The tangent of the given angle, rounded to a specified decimal precision.
#*******************************************************************************
def promptTan():
  opposite = float(input("Please enter the length of the side opposite of of theta (θ): "))
  adjacent = float(input("Please enter the length of the side adjacent of theta (θ): "))
  return setPrecision(opposite / adjacent)




#*******************************************************************************
# promptTrigonometricCalculator
#
# Description: This function acts as a calculator for trigonometric functions. It provides
# options for the user to select whether they want to solve for an angle, side lengths, or
# a trigonometric function. It then guides the user through the necessary prompts based
# on their selection to calculate and display the results.
#
# Input: The function interacts with the user to gather input for solving trigonometric
# problems. It takes input for the type of problem to solve, the trigonometric function,
# and angle or side lengths as necessary.
#
# Output: The function provides the results of the trigonometric calculations based on the
# user's selections.
#
# Parameters: None
#
# Returns: None
#*******************************************************************************
def promptTrigonometricCalculator():
  trigMenuOptions = ["Angle (Theta)", "Side Lengths"] # [TODO: Add "Trig Functions" to Options]
  baseTrigFunctions = ['sin', 'cos', 'tan']
  # fullTrigFunctions = baseTrigFunctions + ["sec", "csc", "cot"]
  trigFuncDescriptionMenu = [
    "sin (The side lengths opposite theta and the hypotenuse are known.)",
    "cos (The side lengths adjecent theta and the hypotenuse are known.)",
    "tan (The side lengths opposite theta and the adjacent to theta are known.)"
  ]
  trigonomicSides = ["Opposite", "Adjacent", "Hypotenuse"]

  trigFuncSelectionHeader = "Trigonomic Function Selection"
  trigSideSelectionHeader = "Trigonomic Side Selection"
  trigCalculatorHeader = "Trig Function Calculator"
  
  trigFuncSelectionPrompt = "Which trigonomic function are you using (sin, cos, tan)?: "
  sidelenSelectionPrompt = "Which side length are you attempting to solve for\
(Opposite, Adjacent, or Hypotenuse)?: "
  TrigInputPrompt = "What are you trying to solve for?: "

  
  displayMenu(trigCalculatorHeader, trigMenuOptions)
  selection = validateMenuChoice(TrigInputPrompt, len(trigMenuOptions))
  print()

  if selection == 0: # [MAIN BRANCH] Solving for an angle
      displayMenu(trigFuncSelectionHeader, trigFuncDescriptionMenu)
      trigFuncSelection = validateMenuChoice(trigFuncSelectionPrompt, len(baseTrigFunctions))
      ratio = 0

      if trigFuncSelection == 0: # Solving for sin
          ratio = promptSin()
          # Use arcsin to calculate the angle
          angle = math.degrees(math.asin(ratio))
          print(f"\nThe angle (in degrees) is: {setPrecision(angle)}")

      elif trigFuncSelection == 1: # Solving for cos
          ratio = promptCos()
          # Use arccos to calculate the angle
          angle = math.degrees(math.acos(ratio))
          print(f"\nThe angle (in degrees) is: {setPrecision(angle)}")

      elif trigFuncSelection == 2: # Solving for tan
          ratio = promptTan()
          # Use arctan to calculate the angle
          angle = math.degrees(math.atan(ratio))
          print(f"\nThe angle (in degrees) is: {setPrecision(angle)}")
    

  elif selection == 1: # [MAIN BRANCH] Solving for a side length
      displayMenu(trigSideSelectionHeader, trigonomicSides)
      trigSideSelection = validateMenuChoice(sidelenSelectionPrompt, len(trigonomicSides))

      if trigSideSelection == 0: # Solving for opposite 
          angle = float(input("Enter the angle (in degrees): "))
          hypotenuse = float(input("Enter the length of the hypotenuse: "))
          # Use sin to calculate the length of the opposite side
          opposite = math.sin(math.radians(angle)) * hypotenuse
          print(f"The length of the opposite side is: {setPrecision(opposite)}")

      elif trigSideSelection == 1: # Solving for adjacent side
          angle = float(input("Enter the angle (in degrees): "))
          hypotenuse = float(input("Enter the length of the hypotenuse: "))
          # Use cos to calculate the length of the adjacent side
          adjacent = math.cos(math.radians(angle)) * hypotenuse
          print(f"The length of the adjacent side is: {setPrecision(adjacent)}")

      elif trigSideSelection == 2: # Solving for hypotenuse
          angle = float(input("Enter the angle (in degrees): "))
          opposite = float(input("Enter the length of the opposite side: "))
          # Use sin to calculate the length of the hypotenuse
          hypotenuse = opposite / math.sin(math.radians(angle))
          print(f"The length of the hypotenuse is: {setPrecision(hypotenuse)}")



  
  

  



  


