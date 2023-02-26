import string
import sys


class MarkovResult(object):
    def __init__(self, completed, steps, failReason):
        self.completed = completed
        self.steps = steps
        self.failReason = failReason


def readRules(params):
    rules = []
    rul_t = open(params['ruleFile'])
    cmdIdx = 1
    print('-----------------------------------')
    for stri in rul_t:
        print("{0}      ({1})".format(stri[0:-1], cmdIdx))
        i = False
        if "->." in stri:
            i = True
        l_s = stri.strip(string.whitespace).split("->")
        n1 = l_s[0]
        n2 = l_s[1].strip(".")
        rules.append((n1, n2, i, cmdIdx))
        cmdIdx += 1

    print()
    print('-----------------------------------')
    return rules


def runMarkov(data, rules, params):
    steps = 0
    while True:
        c = True
        b = False
        for rule in rules:
            ch = data.find(rule[0])
            if ch == -1:
                continue
            else:
                c = False
                data = data[0:ch] + rule[1] + data[ch+len(rule[0]):]
                steps += 1
                print('>> {0}   ({1})'.format(data, rule[-1]))

                if not params['force']:
                    input()

                if rule[2]:
                    b = True
                    break
                else:
                    break

        if b or c:
            return MarkovResult(True, steps, None)
        if steps >= params['stepsLimit']:
            return MarkovResult(False, steps, 'too many steps')


def readParams():
    params = sys.argv[1:] if len(sys.argv) > 1 else []
    parsedParams = {
        'force': False,
        'stepsLimit': 100,
        'ruleFile': 'code.txt'
    }
    for idx, param in enumerate(params):
        if param == '-f':
            parsedParams['force'] = True
        elif param == '-l':
            parsedParams['stepsLimit'] = int(params[idx + 1])
        elif param == '-r':
            parsedParams['ruleFile'] = str(params[idx + 1])

    return parsedParams   


params = readParams()
rules = readRules(params)
data = str(input())
results = runMarkov(data, rules, params)

if results.completed:
    print('------> Success complete <---------')
    print('Steps count:', results.steps)
else:
    print('------> Failed <---------')
    print('Reason:', results.failReason)

