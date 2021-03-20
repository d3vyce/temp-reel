import xlsxwriter

f = open("output", "r")
input = f.read()

excel = xlsxwriter.Workbook('test.xlsx')
excel_sheet = excel.add_worksheet()
test_cell = excel.add_format()
test_cell.set_bg_color('green')

max = 0

for i in input:
    test = int(i)
    if test > max:
        max = test

for i in range(1, max+1):
    row = str(i)
    excel_sheet.write(i, 0, "Tache "+row)

col = 1
for i in input:
    row = int(i)
    excel_sheet.write(0, col, col)
    excel_sheet.write(row, col, "", test_cell)
    col = col+1

excel.close()