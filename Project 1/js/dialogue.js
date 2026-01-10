import { renderText } from "./renderer.js"
import { setFlag } from "./state.js"

let active = false
let data = null
let current = null

export async function openDialogue(path) {
  active = true
  const res = await fetch(path)
  data = await res.json()
  current = "start"
  draw()
}

export function isDialogueActive() {
  return active
}

export function handleDialogueInput(key) {
  if (!active) return

  const node = data[current]

  if (node.choices && node.choices[key]) {
    const choice = node.choices[key]
    if (choice.flag) setFlag(choice.flag)
    current = choice.next
    draw()
    return
  }

  if (key === "Enter" && !node.choices) {
    active = false
  }
}

function draw() {
  const node = data[current]
  let output = node.text.join("\n")

  if (node.choices) {
    output += "\n\n"
    for (const k in node.choices) {
      output += `${k}) ${node.choices[k].text}\n`
    }
  }

  renderText(output)
}
