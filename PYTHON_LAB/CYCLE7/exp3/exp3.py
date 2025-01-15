import csv
def readcsv(file_name):
    try:
        with open(file_name,'r') as file:
            csvreader=csv.reader(file)
            for row in csvreader:
                print(row)
    except FileNotFoundError:
        print(f"{filename} not found")
    except Exception as e:
        print(f"An error occured={e}")
if __name__=="__main__":
    filename="thirdqs.csv"
    readcsv(filename)
