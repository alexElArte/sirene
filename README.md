# Sirene
Reproduction de différent son de sirène avec un arduino et un buzzer passif
## Fréquence
u = cycles/min
+---------+--------+ +---------+-------------+
|  Type   | POLICE | |  Type   | GENDARMERIE |
|  Ton 1  | 435 hz | |  Ton 1  |   435 hz    |
|  Ton 2  | 580 hz | |  Ton 2  |   732 hz    |
|  Ton 3  |  none  | |  Ton 3  |    none     |
|  Ton 4  |  none  | |  Ton 4  |    none     |
| Cadence | 50-60u | | Cadence |   50-60u    |
+---------+--------+ +---------+-------------+
+---------+---------+ +---------+----------+
|  Type   | POMPIER | |  Type   | UMH/SAMU |
|  Ton 1  | 435 hz  | |  Ton 1  |  435 hz  |
|  Ton 2  | 488 hz  | |  Ton 2  |  651 hz  |
|  Ton 3  |  none   | |  Ton 3  |   none   |
|  Ton 4  |  none   | |  Ton 4  |   none   |
| Cadence | 25-30u  | | Cadence |  50-60u  |
+---------+---------+ +---------+----------+
+---------+-------------+
|  Type   |  AMBULANCE  |
|  Ton 1  |   420 hz    |
|  Ton 2  |   516 hz    |
|  Ton 3  |   420 hz    |
|  Ton 4  | noTone 1.5s |
| Cadence |   50-60u    |
+---------+-------------+
