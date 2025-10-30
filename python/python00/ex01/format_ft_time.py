import datetime

date = datetime.datetime.now()
epoch = datetime.datetime.fromtimestamp(0)

dif = date - epoch

total_seconds = dif.total_seconds()

seconds_formated = f"{total_seconds:,.4f}"
scientific_notation = f"{total_seconds:.2e}"
scientific_formated = date.strftime("%b %d %Y")
print(
    f"Seconds since January 1, 1970: {seconds_formated} \
      or {scientific_notation} in scientific notation"
)
print(scientific_formated)
